import os
import os.path
import glob
import datetime
import MySQLdb as mdb
from xlwt import Workbook,Style
import re
import sys

# default encode utf-8
reload(sys)
sys.setdefaultencoding('utf-8')


# mysql username, password and charset
MYSQL_USERNAME = "root"
MYSQL_PASSWORD = "azmohan"
MYSQL_CHARSET = "utf8"
# database
DATABASE_BE_COMPARED = "base"
DATABASE_COMPARE = "advance"

def getBeforeYesterdayStr():
    now = datetime.datetime.now()
    delta = datetime.timedelta(days=2)
    yesterday = now -delta
    return yesterday.strftime("%y-%m-%d")

def getYesterdayStr():
    now = datetime.datetime.now()
    delta = datetime.timedelta(days=1)
    yesterday = now -delta
    return yesterday.strftime("%y-%m-%d")

def getTodayStr():
    now = datetime.datetime.now()
    return now.strftime("%y-%m-%d")

def getSqlFileByDate(rootDir,date):
    for filename in glob.glob(rootDir+os.sep+"*"+date+".sql"):
        if os.path.isfile(filename):
            return filename
    return ""
def importSqlFileToDatabase(database,sqlFile):
    cmd = "mysql -u"+MYSQL_USERNAME+" -p" + MYSQL_PASSWORD + \
            " --default-character-set=" + MYSQL_CHARSET + " " + database + \
            " < " + sqlFile
    print cmd
    os.system(cmd)

def importDatabase():
    dSql = getSqlFileByDate(os.getcwd(),getYesterdayStr())
    ySql = getSqlFileByDate(os.getcwd(),getBeforeYesterdayStr())
    pSql = os.getcwd() + "/products.sql"
    assert len(pSql) > 0
    assert len(ySql) > 0
    assert len(dSql) > 0
    importSqlFileToDatabase(DATABASE_BE_COMPARED,ySql)
    importSqlFileToDatabase(DATABASE_BE_COMPARED,pSql)
    importSqlFileToDatabase(DATABASE_COMPARE,dSql)

def selectDatabase(database,sql):
    con = mdb.connect('localhost',MYSQL_USERNAME,MYSQL_PASSWORD,database)
    cur = con.cursor(mdb.cursors.DictCursor)
    try:
        cur.execute(sql)
        result = cur.fetchall()
    except:
        cur.close()
        con.close()
        print "Error: unable to fecth data"
    cur.close()
    con.close()
    return result

def getUserAndPushCntsByChannelId(actUsers,channelId):
    cArray = [];
    userCnts = 0
    pushCnts = 0
    for user in actUsers:
        if(cmp(channelId,user["channel_id"]) == 0):
            userCnts = user["userCnts"]
            pushCnts = user["pushCnts"]
            break
    cArray.append(userCnts)
    cArray.append(pushCnts)
    return cArray


def addItemtoInfoArray(infoArray,user,yActUsers,products):
    channelId = user["channel_id"]
    company = "Unknown"
    app = "Unknown"
    dayActCnts = user["userCnts"]
    cArray = getUserAndPushCntsByChannelId(yActUsers,channelId)
    dayIncCnts = dayActCnts - cArray[0]
    pushCnts = user["pushCnts"]
    status = 0
    for product in products:
        id = product["companycode"]+product["branch"] + product["type"] + product["line"] +product["code"]
        if (cmp(channelId[0:18],id) == 0):
            company = product["company"].decode("utf-8")
            app = product["name"].decode("utf-8")
            status = product["status"]
            print (company + "    " +app)
            print status
            break
    itemDict = {'a':''}
    itemDict['a'] = channelId
    itemDict['b'] = company
    itemDict['c'] = app
    itemDict['d'] = dayIncCnts
    itemDict['e'] = dayActCnts
    itemDict['f'] = pushCnts
    itemDict['g'] = status
    infoArray.append(itemDict)

def getStatisticInfo():
    infoArray = []
    products = selectDatabase(DATABASE_BE_COMPARED,"SELECT * FROM products")
    sql = "SELECT channel_id,COUNT(*) as 'userCnts',SUM(validcount) as 'pushCnts' FROM statistic_info group by channel_id"
    yActUsers = selectDatabase(DATABASE_BE_COMPARED,sql)
    tActUsers = selectDatabase(DATABASE_COMPARE,sql)
    for user in tActUsers:
        addItemtoInfoArray(infoArray,user,yActUsers,products)

    return infoArray

def getOpenChannelInfo():
    infoArray = []
    products = selectDatabase(DATABASE_BE_COMPARED,"SELECT company,name,status FROM products WHERE status = 1")
    return products


# save to excel
def getFieldNames():
    return {'a':'channelId','b':'company','c':'product','d':'dayIncCnts','e':'dayActCnts','f':'pushCnts','g':'status'}

def getOpenPFieldNames():
    return {'b':'company','c':'product','g':'status'}

def convDict2SortedList(dictRow):
    listRow = []
    keys = dictRow.keys();
    keys.sort()
    for key in keys:
        listRow.append(dictRow[key])
    return listRow

def write2Excel(fileName,fieldNames,rows):
    wb = Workbook(encoding="utf-8")
    ws = wb.add_sheet('statistic',cell_overwrite_ok=True)

    row = ws.row(0)
    listRow = convDict2SortedList(fieldNames)
    for j in range(len(listRow)):
        row.write(j,listRow[j])

    i_row = 1
    for i in range(i_row,len(rows)+i_row):
        row = ws.row(i)
        listRow = convDict2SortedList(rows[i - i_row])
        for j in range(len(listRow)):
            if len(str(listRow[j])) > 15:
                row.set_cell_text(j,listRow[j])
            else:
                row.write(j,listRow[j])
    wb.save(fileName)


if __name__=="__main__":
    importDatabase()
    infos = getStatisticInfo()
    xlsFile = "statistic_"+getTodayStr()+".xls"
    write2Excel(xlsFile,getFieldNames(),infos)
    openInfos = getOpenChannelInfo()
    openxlsFile = "open_products_" + getTodayStr()+".xls"
    write2Excel(openxlsFile,getOpenPFieldNames(),openInfos)



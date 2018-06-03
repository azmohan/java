-- MySQL dump 10.13  Distrib 5.5.40, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: pmsg_db
-- ------------------------------------------------------
-- Server version	5.5.40-0ubuntu0.14.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `statistic_info`
--

DROP TABLE IF EXISTS `statistic_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `statistic_info` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `updatetimes` bigint(20) NOT NULL DEFAULT '1',
  `channel_id` text,
  `client_id` text,
  `area` text,
  `imei` text,
  `imsi` text,
  `wifi` text,
  `phone_num` text,
  `pkg_name` text,
  `net_type` text,
  `wifi_mac` text,
  `roamed` int(11) DEFAULT NULL,
  `rooted` int(11) DEFAULT NULL,
  `createdate` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `updatedate` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `statistic_info`
--

LOCK TABLES `statistic_info` WRITE;
/*!40000 ALTER TABLE `statistic_info` DISABLE KEYS */;
INSERT INTO `statistic_info` VALUES (1,12,'ABCDABABABABCDEFGHABCDEFGHIJKLMNO','12345678901234567890123456789012','??',NULL,NULL,'1','','com.test.boothert','wifi','44:91:db:46:f3:8b',0,0,'2014-11-29 08:06:50','2014-11-29 08:34:06'),(2,53,'HLNGSAA2L1ZZZZZZZZAK98RG3HOF4JK80','46286d668456ccd9c6104e1556030356','??',NULL,NULL,'1','','com.android.localImpls','wifi','44:91:db:46:f3:8b',0,0,'2014-11-29 08:07:52','2014-11-29 15:55:36');
/*!40000 ALTER TABLE `statistic_info` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2014-12-10  0:20:49

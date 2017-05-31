-- MySQL dump 10.13  Distrib 5.7.18, for Linux (i686)
--
-- Host: 192.168.1.14    Database: plcm
-- ------------------------------------------------------
-- Server version	5.7.18-0ubuntu0.16.04.1

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
-- Table structure for table `item`
--

DROP TABLE IF EXISTS `item`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `item` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(32) DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL,
  `plc_id` int(11) DEFAULT NULL,
  `area` int(1) DEFAULT NULL,
  `DB` int(1) DEFAULT NULL,
  `start` int(11) DEFAULT NULL,
  `len` int(11) DEFAULT NULL,
  `mode` int(1) DEFAULT NULL,
  `timer` int(11) DEFAULT NULL,
  `write_mode` int(1) DEFAULT NULL,
  `active` int(1) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item`
--

LOCK TABLES `item` WRITE;
/*!40000 ALTER TABLE `item` DISABLE KEYS */;
INSERT INTO `item` VALUES (1,'new_item3','',2,129,1,2,3,0,10,0,1),(3,'new_item99','item description',3,129,0,0,1,0,10,0,0),(4,'new_item',NULL,2,3,0,0,1,0,10,0,0);
/*!40000 ALTER TABLE `item` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `log`
--

DROP TABLE IF EXISTS `log`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `log` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `portion_id` int(11) DEFAULT NULL,
  `answer` tinyblob,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `log`
--

LOCK TABLES `log` WRITE;
/*!40000 ALTER TABLE `log` DISABLE KEYS */;
/*!40000 ALTER TABLE `log` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `param`
--

DROP TABLE IF EXISTS `param`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `param` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `type` varchar(32) DEFAULT NULL,
  `name` varchar(128) DEFAULT NULL,
  `value` int(11) DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=39 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `param`
--

LOCK TABLES `param` WRITE;
/*!40000 ALTER TABLE `param` DISABLE KEYS */;
INSERT INTO `param` VALUES (1,'proto','daveProtoMPI',0,'/* MPI for S7 300/400 */'),(2,'proto','daveProtoMPI2',1,'/* MPI for S7 300/400, \"Andrew\'s version\" without STX */'),(3,'proto','daveProtoMPI3',2,'/* MPI for S7 300/400, Step 7 Version, not yet implemented */'),(4,'proto','daveProtoMPI4',3,'/* MPI for S7 300/400, \"Andrew\'s version\" with STX */'),(5,'proto','daveProtoPPI',10,'/* PPI for S7 200 */'),(6,'proto','daveProtoAS511',20,'/* S5 programming port protocol */'),(7,'proto','daveProtoS7online',50,'/* use s7onlinx.dll for transport */'),(8,'proto','daveProtoISOTCP',122,'/* ISO over TCP */'),(9,'proto','daveProtoISOTCP243',123,'/* ISO over TCP with CP243 */'),(10,'proto','daveProtoMPI_IBH',223,'/* MPI with IBH NetLink MPI to ethernet gateway */'),(11,'proto','daveProtoPPI_IBH',224,'/* PPI with IBH NetLink PPI to ethernet gateway */'),(12,'proto','daveProtoNLpro',230,'/* MPI with NetLink Pro MPI to ethernet gateway */'),(13,'proto','daveProtoUserTransport',255,'/* Libnodave will pass the PDUs of S7 Communication to user */'),(14,'speed','daveSpeed9k',0,''),(15,'speed','daveSpeed19k',1,'9k    1'),(16,'speed','daveSpeed187k',2,''),(17,'speed','daveSpeed500k',3,''),(18,'speed','daveSpeed1500k',4,''),(19,'speed','daveSpeed45k',5,'k    5'),(20,'speed','daveSpeed93k',6,''),(21,'area','daveSysInfo',3,'/* System info of 200 family */'),(22,'area','daveSysFlags',5,'/* System flags of 200 family */'),(23,'area','daveAnaIn',6,'/* analog inputs of 200 family */'),(24,'area','daveAnaOut',7,'/* analog outputs of 200 family */'),(25,'area','daveP',128,'/* direct peripheral access */'),(26,'area','daveInputs',129,''),(27,'area','daveOutputs',130,''),(28,'area','daveFlags',131,''),(29,'area','daveDB',132,'/* data blocks */'),(30,'area','daveDI',133,'/* instance data blocks */'),(31,'area','daveLocal',134,'/* not tested */'),(32,'area','daveV',135,'/* don\'t know what it is */'),(33,'area','daveCounter',28,'/* S7 counters */'),(34,'area','daveTimer',29,'/* S7 timers */'),(35,'area','daveCounter200',30,'/* IEC counters (200 family) */'),(36,'area','daveTimer200',31,'/* IEC timers (200 family) */'),(37,'area','daveSysDataS5',134,'/* system data area ? */'),(38,'area','daveRawMemoryS5',0,'/* just the raw memory */');
/*!40000 ALTER TABLE `param` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `plc`
--

DROP TABLE IF EXISTS `plc`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `plc` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(32) DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL,
  `ip` varchar(15) DEFAULT NULL,
  `daveProto` int(3) DEFAULT NULL,
  `daveSpeed` int(2) DEFAULT NULL,
  `daveTimeout` int(11) DEFAULT NULL,
  `MPI` int(2) DEFAULT NULL,
  `rack` int(2) DEFAULT NULL,
  `slot` int(2) DEFAULT NULL,
  `active` int(1) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `plc`
--

LOCK TABLES `plc` WRITE;
/*!40000 ALTER TABLE `plc` DISABLE KEYS */;
INSERT INTO `plc` VALUES (2,'line 1','description','10.0.3.5',122,2,5000000,2,0,2,1),(3,'new_plc',NULL,NULL,122,2,5000000,2,0,2,0);
/*!40000 ALTER TABLE `plc` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `user` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(32) DEFAULT NULL,
  `password` varchar(32) DEFAULT NULL,
  `role` int(2) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2017-05-31 17:06:03

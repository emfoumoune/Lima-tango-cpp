//=============================================================================
//
// file :         PcoClass.h
//
// description :  Include for the PcoClass root class.
//                This class is the singleton class for
//                the Pco device class.
//                It contains all properties and methods which the 
//                Pco requires only once e.g. the commands.
//			
// project :      TANGO Device Server
//
// $Author:  $
//
// $Revision:  $
// $Date:  $
//
// SVN only:
// $HeadURL: $
//
// CVS only:
// $Source:  $
// $Log:  $
//
// copyleft :     European Synchrotron Radiation Facility
//                BP 220, Grenoble 38043
//                FRANCE
//
//=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================

#ifndef _PCOCLASS_H
#define _PCOCLASS_H

#include <tango.h>
#include <Pco.h>
#include "Pco.h"


namespace Pco_ns
{//=====================================
//	Define classes for attributes
//=====================================
class dllVersionAttrib: public Tango::Attr
{
public:
	dllVersionAttrib():Attr("dllVersion", Tango::DEV_STRING, Tango::READ) {};
	~dllVersionAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Pco *>(dev))->read_dllVersion(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Pco *>(dev))->is_dllVersion_allowed(ty);}
};

class forcedFIFOModeAttrib: public Tango::Attr
{
public:
	forcedFIFOModeAttrib():Attr("forcedFIFOMode", Tango::DEV_BOOLEAN, Tango::READ_WRITE) {};
	~forcedFIFOModeAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Pco *>(dev))->read_forcedFIFOMode(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<Pco *>(dev))->write_forcedFIFOMode(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Pco *>(dev))->is_forcedFIFOMode_allowed(ty);}
};

class sensorTemperatureAttrib: public Tango::Attr
{
public:
	sensorTemperatureAttrib():Attr("sensorTemperature", Tango::DEV_FLOAT, Tango::READ) {};
	~sensorTemperatureAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Pco *>(dev))->read_sensorTemperature(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Pco *>(dev))->is_sensorTemperature_allowed(ty);}
};

class cameraModelAttrib: public Tango::Attr
{
public:
	cameraModelAttrib():Attr("cameraModel", Tango::DEV_STRING, Tango::READ) {};
	~cameraModelAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Pco *>(dev))->read_cameraModel(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Pco *>(dev))->is_cameraModel_allowed(ty);}
};

class currentRecordedFrameAttrib: public Tango::Attr
{
public:
	currentRecordedFrameAttrib():Attr("currentRecordedFrame", Tango::DEV_ULONG, Tango::READ) {};
	~currentRecordedFrameAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Pco *>(dev))->read_currentRecordedFrame(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Pco *>(dev))->is_currentRecordedFrame_allowed(ty);}
};

class doubleImageAttrib: public Tango::Attr
{
public:
	doubleImageAttrib():Attr("doubleImage", Tango::DEV_BOOLEAN, Tango::READ_WRITE) {};
	~doubleImageAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Pco *>(dev))->read_doubleImage(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<Pco *>(dev))->write_doubleImage(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Pco *>(dev))->is_doubleImage_allowed(ty);}
};

class pixelRateAttrib: public Tango::Attr
{
public:
	pixelRateAttrib():Attr("pixelRate", Tango::DEV_STRING, Tango::READ_WRITE) {};
	~pixelRateAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<Pco *>(dev))->read_pixelRate(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<Pco *>(dev))->write_pixelRate(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<Pco *>(dev))->is_pixelRate_allowed(ty);}
};

//=========================================
//	Define classes for commands
//=========================================
class GetCamInfoCmd : public Tango::Command
{
public:
	GetCamInfoCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	GetCamInfoCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~GetCamInfoCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Pco *>(dev))->is_GetCamInfo_allowed(any);}
};



class TalkCmd : public Tango::Command
{
public:
	TalkCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	TalkCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~TalkCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<Pco *>(dev))->is_Talk_allowed(any);}
};



//
// The PcoClass singleton definition
//

class
#ifdef WIN32
	__declspec(dllexport)
#endif
	PcoClass : public Tango::DeviceClass
{
public:
//	properties member data

//	add your own data members here
//------------------------------------

public:
	Tango::DbData	cl_prop;
	Tango::DbData	cl_def_prop;
	Tango::DbData	dev_def_prop;

//	Method prototypes
	static PcoClass *init(const char *);
	static PcoClass *instance();
	~PcoClass();
	Tango::DbDatum	get_class_property(string &);
	Tango::DbDatum	get_default_device_property(string &);
	Tango::DbDatum	get_default_class_property(string &);
	
protected:
	PcoClass(string &);
	static PcoClass *_instance;
	void command_factory();
	void get_class_property();
	void attribute_factory(vector<Tango::Attr *> &);
	void write_class_property();
	void set_default_property();
	string get_cvstag();
	string get_cvsroot();

private:
	void device_factory(const Tango::DevVarStringArray *);
};


}	//	namespace Pco_ns

#endif // _PCOCLASS_H

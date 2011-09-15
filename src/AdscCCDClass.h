//=============================================================================
//
// file :         AdscCCDClass.h
//
// description :  Include for the AdscCCDClass root class.
//                This class is the singleton class for
//                the AdscCCD device class.
//                It contains all properties and methods which the 
//                AdscCCD requires only once e.g. the commands.
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

#ifndef _ADSCCCDCLASS_H
#define _ADSCCCDCLASS_H


#include <AdscCCD.h>
#include <tango.h>

namespace AdscCCD_ns
{//=====================================
//	Define classes for attributes
//=====================================
class fileNameAttrib: public Tango::Attr
{
public:
	fileNameAttrib():Attr("fileName", Tango::DEV_STRING, Tango::READ_WRITE) {};
	~fileNameAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdscCCD *>(dev))->read_fileName(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdscCCD *>(dev))->write_fileName(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdscCCD *>(dev))->is_fileName_allowed(ty);}
};

class imagePathAttrib: public Tango::Attr
{
public:
	imagePathAttrib():Attr("imagePath", Tango::DEV_STRING, Tango::READ_WRITE) {};
	~imagePathAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdscCCD *>(dev))->read_imagePath(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdscCCD *>(dev))->write_imagePath(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdscCCD *>(dev))->is_imagePath_allowed(ty);}
};

//=========================================
//	Define classes for commands
//=========================================
class SetHeaderParametersCmd : public Tango::Command
{
public:
	SetHeaderParametersCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	SetHeaderParametersCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~SetHeaderParametersCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<AdscCCD *>(dev))->is_SetHeaderParameters_allowed(any);}
};



//
// The AdscCCDClass singleton definition
//

class
#ifdef WIN32
	__declspec(dllexport)
#endif
	AdscCCDClass : public Tango::DeviceClass
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
	static AdscCCDClass *init(const char *);
	static AdscCCDClass *instance();
	~AdscCCDClass();
	Tango::DbDatum	get_class_property(string &);
	Tango::DbDatum	get_default_device_property(string &);
	Tango::DbDatum	get_default_class_property(string &);
	
protected:
	AdscCCDClass(string &);
	static AdscCCDClass *_instance;
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


}	//	namespace AdscCCD_ns

#endif // _ADSCCCDCLASS_H

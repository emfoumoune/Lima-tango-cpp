/*----- PROTECTED REGION ID(TeledynePI.h) ENABLED START -----*/
//=============================================================================
//
// file :        TeledynePI.h
//
// description : Include file for the TeledynePI class
//
// project :     
//
// This file is part of Tango device class.
// 
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
// 
//
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#ifndef TeledynePI_H
#define TeledynePI_H

#include <tango.h>
#include "Factory.h"

//- YAT/YAT4TANGO
#include <yat4tango/PropertyHelper.h>
#include <yat4tango/InnerAppender.h>

#include "lima/HwInterface.h"
#include "lima/CtControl.h"
#include "lima/CtAcquisition.h"
#include "lima/CtImage.h"
#include <PrincetonInterface.h>

#define MAX_ATTRIBUTE_STRING_LENGTH     256

/*----- PROTECTED REGION END -----*/	//	TeledynePI.h

/**
 *  TeledynePI class description:
 *    
 */

namespace TeledynePI_ns
{
enum _gainEnum : short{
} ;
typedef _gainEnum gainEnum;

/*----- PROTECTED REGION ID(TeledynePI::Additional Class Declarations) ENABLED START -----*/

//	Additional Class Declarations

/*----- PROTECTED REGION END -----*/	//	TeledynePI::Additional Class Declarations

class TeledynePI : public TANGO_BASE_CLASS
{

/*----- PROTECTED REGION ID(TeledynePI::Data Members) ENABLED START -----*/

public :
    //    Add your own data members here
    //-----------------------------------------
        Tango::DevUShort            attr_gain_cache;
        Tango::DevDouble            attr_temperatureTarget_cache;

    //    Here is the Start of the automatic code generation part
    //-------------------------------------------------------------    
		Tango::DevDouble	attr_temperatureTarget_write;
		gainEnum	attr_gain_write;
		Tango::DevDouble	attr_adcRate_write;

/*----- PROTECTED REGION END -----*/	//	TeledynePI::Data Members

//	Device property data members
public:
	//	TemperatureTargetAtInit:	Define the target temperature to be used at device initialization
	Tango::DevDouble	temperatureTargetAtInit;

//	Attribute data members
public:
	Tango::DevDouble	*attr_temperature_read;
	Tango::DevDouble	*attr_temperatureTarget_read;
	gainEnum	*attr_gain_read;
	Tango::DevDouble	*attr_adcRate_read;

//	Constructors and destructors
public:
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	TeledynePI(Tango::DeviceClass *cl,string &s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	TeledynePI(Tango::DeviceClass *cl,const char *s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device name
	 *	@param d	Device description.
	 */
	TeledynePI(Tango::DeviceClass *cl,const char *s,const char *d);
	/**
	 * The device object destructor.
	 */
	~TeledynePI() {delete_device();};


//	Miscellaneous methods
public:
	/*
	 *	will be called at device destruction or at init command.
	 */
	void delete_device();
	/*
	 *	Initialize the device
	 */
	virtual void init_device();
	/*
	 *	Read the device properties from database
	 */
	void get_device_property();
	/*
	 *	Always executed method before execution command method.
	 */
	virtual void always_executed_hook();


//	Attribute methods
public:
	//--------------------------------------------------------
	/*
	 *	Method      : TeledynePI::read_attr_hardware()
	 *	Description : Hardware acquisition for attributes.
	 */
	//--------------------------------------------------------
	virtual void read_attr_hardware(vector<long> &attr_list);
	//--------------------------------------------------------
	/*
	 *	Method      : TeledynePI::write_attr_hardware()
	 *	Description : Hardware writing for attributes.
	 */
	//--------------------------------------------------------
	virtual void write_attr_hardware(vector<long> &attr_list);

/**
 *	Attribute temperature related methods
 *	Description: The current temperature  (Degree Celsius)
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_temperature(Tango::Attribute &attr);
	virtual bool is_temperature_allowed(Tango::AttReqType type);
/**
 *	Attribute temperatureTarget related methods
 *	Description: Define the Temperature target of the detector (in deg Celsius)
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_temperatureTarget(Tango::Attribute &attr);
	virtual void write_temperatureTarget(Tango::WAttribute &attr);
	virtual bool is_temperatureTarget_allowed(Tango::AttReqType type);
/**
 *	Attribute gain related methods
 *	Description: Define the gain of the detector [LOW, MEDIUM, HIGH]
 *
 *	Data type:	Tango::DevEnum
 *	Attr type:	Scalar
 */
	virtual void read_gain(Tango::Attribute &attr);
	virtual void write_gain(Tango::WAttribute &attr);
	virtual bool is_gain_allowed(Tango::AttReqType type);
/**
 *	Attribute adcRate related methods
 *	Description: Define the speed at which pixels are digitized (MHz)
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_adcRate(Tango::Attribute &attr);
	virtual void write_adcRate(Tango::WAttribute &attr);
	virtual bool is_adcRate_allowed(Tango::AttReqType type);


	//--------------------------------------------------------
	/**
	 *	Method      : TeledynePI::add_dynamic_attributes()
	 *	Description : Add dynamic attributes if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_attributes();




//	Command related methods
public:
	/**
	 *	Command State related method
	 *	Description: This command gets the device state (stored in its device_state data member) and returns it to the caller.
	 *
	 *	@returns Device state
	 */
	virtual Tango::DevState dev_state();


	//--------------------------------------------------------
	/**
	 *	Method      : TeledynePI::add_dynamic_commands()
	 *	Description : Add dynamic commands if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_commands();

/*----- PROTECTED REGION ID(TeledynePI::Additional Method prototypes) ENABLED START -----*/
	bool is_device_initialized(){return m_is_device_initialized;};
//	Additional Method prototypes
protected :	
	//	Add your own data members here
	//-----------------------------------------

    //state & status stuff
    bool                        m_is_device_initialized ;
    stringstream                m_status_message;
    
	//lima OBJECTS
	lima::Princeton::Interface*		m_hw;
    lima::CtControl*                m_ct;
/*----- PROTECTED REGION END -----*/	//	TeledynePI::Additional Method prototypes
};

/*----- PROTECTED REGION ID(TeledynePI::Additional Classes Definitions) ENABLED START -----*/

//	Additional Classes Definitions
enum class GainMode : short
{
	LOW,
	MEDIUM,
	HIGH
};

/*----- PROTECTED REGION END -----*/	//	TeledynePI::Additional Classes Definitions

}	//	End of namespace

#endif   //	TeledynePI_H

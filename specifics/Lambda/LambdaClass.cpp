/*----- PROTECTED REGION ID(LambdaClass.cpp) ENABLED START -----*/
static const char *RcsId      = "$Id:  $";
static const char *TagName    = "$Name:  $";
static const char *CvsPath    = "$Source:  $";
static const char *SvnPath    = "$HeadURL:  $";
static const char *HttpServer = "http://www.esrf.eu/computing/cs/tango/tango_doc/ds_doc/";
//=============================================================================
//
// file :        LambdaClass.cpp
//
// description : C++ source for the LambdaClass.
//               A singleton class derived from DeviceClass.
//               It implements the command and attribute list
//               and all properties and methods required
//               by the Lambda once per process.
//
// project :     XSpectrum Lambda detector TANGO specific device.
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
// $Author:  $
//
// $Revision:  $
// $Date:  $
//
// $HeadURL:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#include <LambdaClass.h>

/*----- PROTECTED REGION END -----*/	//	LambdaClass.cpp

//-------------------------------------------------------------------
/**
 *	Create LambdaClass singleton and
 *	return it in a C function for Python usage
 */
//-------------------------------------------------------------------
extern "C" {
#ifdef _TG_WINDOWS_

__declspec(dllexport)

#endif

	Tango::DeviceClass *_create_Lambda_class(const char *name) {
		return Lambda_ns::LambdaClass::init(name);
	}
}

namespace Lambda_ns
{
//===================================================================
//	Initialize pointer for singleton pattern
//===================================================================
LambdaClass *LambdaClass::_instance = NULL;

//--------------------------------------------------------
/**
 * method : 		LambdaClass::LambdaClass(string &s)
 * description : 	constructor for the LambdaClass
 *
 * @param s	The class name
 */
//--------------------------------------------------------
LambdaClass::LambdaClass(string &s):Tango::DeviceClass(s)
{
	cout2 << "Entering LambdaClass constructor" << endl;
	set_default_property();
	write_class_property();

	/*----- PROTECTED REGION ID(LambdaClass::constructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LambdaClass::constructor

	cout2 << "Leaving LambdaClass constructor" << endl;
}

//--------------------------------------------------------
/**
 * method : 		LambdaClass::~LambdaClass()
 * description : 	destructor for the LambdaClass
 */
//--------------------------------------------------------
LambdaClass::~LambdaClass()
{
	/*----- PROTECTED REGION ID(LambdaClass::destructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LambdaClass::destructor

	_instance = NULL;
}


//--------------------------------------------------------
/**
 * method : 		LambdaClass::init
 * description : 	Create the object if not already done.
 *                  Otherwise, just return a pointer to the object
 *
 * @param	name	The class name
 */
//--------------------------------------------------------
LambdaClass *LambdaClass::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new LambdaClass(s);
		}
		catch (bad_alloc &)
		{
			throw;
		}
	}
	return _instance;
}

//--------------------------------------------------------
/**
 * method : 		LambdaClass::instance
 * description : 	Check if object already created,
 *                  and return a pointer to the object
 */
//--------------------------------------------------------
LambdaClass *LambdaClass::instance()
{
	if (_instance == NULL)
	{
		cerr << "Class is not initialised !!" << endl;
		exit(-1);
	}
	return _instance;
}



//===================================================================
//	Command execution method calls
//===================================================================

//===================================================================
//	Properties management
//===================================================================
//--------------------------------------------------------
/**
 *	Method      : LambdaClass::get_class_property()
 *	Description : Get the class property for specified name.
 */
//--------------------------------------------------------
Tango::DbDatum LambdaClass::get_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, returns  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : LambdaClass::get_default_device_property()
 *	Description : Return the default value for device property.
 */
//--------------------------------------------------------
Tango::DbDatum LambdaClass::get_default_device_property(string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : LambdaClass::get_default_class_property()
 *	Description : Return the default value for class property.
 */
//--------------------------------------------------------
Tango::DbDatum LambdaClass::get_default_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}


//--------------------------------------------------------
/**
 *	Method      : LambdaClass::set_default_property()
 *	Description : Set default property (class and device) for wizard.
 *                For each property, add to wizard property name and description.
 *                If default value has been set, add it to wizard property and
 *                store it in a DbDatum.
 */
//--------------------------------------------------------
void LambdaClass::set_default_property()
{
	string	prop_name;
	string	prop_desc;
	string	prop_def;
	vector<string>	vect_data;

	//	Set Default Class Properties

	//	Set Default device Properties
	prop_name = "ConfigFile";
	prop_desc = "Configuration file used to initialize the detector.";
	prop_def  = "/opt/xsp/config/system.yml";
	vect_data.clear();
	vect_data.push_back("/opt/xsp/config/system.yml");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "DistortionCorrection";
	prop_desc = "set distortion correction.<br>\nWhen distortion correction is enabled :<br>\n- Large pixels are divided according to predefined denominator. <br>\n- The values of the pixels are rounded during division. <br>\n- If pixel value is saturated, the division is not applied.<br>";
	prop_def  = "True";
	vect_data.clear();
	vect_data.push_back("True");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "MemorizedEnergyThreshold";
	prop_desc = "Only the device could modify this property <br>\nThe User should never change this property<br>";
	prop_def  = "7";
	vect_data.clear();
	vect_data.push_back("7");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
}

//--------------------------------------------------------
/**
 *	Method      : LambdaClass::write_class_property()
 *	Description : Set class description fields as property in database
 */
//--------------------------------------------------------
void LambdaClass::write_class_property()
{
	//	First time, check if database used
	if (Tango::Util::_UseDb == false)
		return;

	Tango::DbData	data;
	string	classname = get_name();
	string	header;
	string::size_type	start, end;

	//	Put title
	Tango::DbDatum	title("ProjectTitle");
	string	str_title("XSpectrum Lambda detector TANGO specific device.");
	title << str_title;
	data.push_back(title);

	//	Put Description
	Tango::DbDatum	description("Description");
	vector<string>	str_desc;
	str_desc.push_back("Device for Lambda detectors from XSpectrum.");
	description << str_desc;
	data.push_back(description);

	//  Put inheritance
	Tango::DbDatum	inher_datum("InheritedFrom");
	vector<string> inheritance;
	inheritance.push_back("TANGO_BASE_CLASS");
	inher_datum << inheritance;
	data.push_back(inher_datum);

	//	Call database and and values
	get_db_class()->put_property(data);
}

//===================================================================
//	Factory methods
//===================================================================

//--------------------------------------------------------
/**
 *	Method      : LambdaClass::device_factory()
 *	Description : Create the device object(s)
 *                and store them in the device list
 */
//--------------------------------------------------------
void LambdaClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{
	/*----- PROTECTED REGION ID(LambdaClass::device_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LambdaClass::device_factory_before

	//	Create devices and add it into the device list
	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
		device_list.push_back(new Lambda(this, (*devlist_ptr)[i]));
	}

	//	Manage dynamic attributes if any
	erase_dynamic_attributes(devlist_ptr, get_class_attr()->get_attr_list());

	//	Export devices to the outside world
	for (unsigned long i=1 ; i<=devlist_ptr->length() ; i++)
	{
		//	Add dynamic attributes if any
		Lambda *dev = static_cast<Lambda *>(device_list[device_list.size()-i]);
		dev->add_dynamic_attributes();

		//	Check before if database used.
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(dev);
		else
			export_device(dev, dev->get_name().c_str());
	}

	/*----- PROTECTED REGION ID(LambdaClass::device_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LambdaClass::device_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : LambdaClass::attribute_factory()
 *	Description : Create the attribute object(s)
 *                and store them in the attribute list
 */
//--------------------------------------------------------
void LambdaClass::attribute_factory(vector<Tango::Attr *> &att_list)
{
	/*----- PROTECTED REGION ID(LambdaClass::attribute_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LambdaClass::attribute_factory_before
	//	Attribute : configFile
	configFileAttrib	*configfile = new configFileAttrib();
	Tango::UserDefaultAttrProp	configfile_prop;
	configfile_prop.set_description("Configuration file used to initialize the detector");
	//	label	not set for configFile
	//	unit	not set for configFile
	//	standard_unit	not set for configFile
	//	display_unit	not set for configFile
	//	format	not set for configFile
	//	max_value	not set for configFile
	//	min_value	not set for configFile
	//	max_alarm	not set for configFile
	//	min_alarm	not set for configFile
	//	max_warning	not set for configFile
	//	min_warning	not set for configFile
	//	delta_t	not set for configFile
	//	delta_val	not set for configFile
	
	configfile->set_default_properties(configfile_prop);
	//	Not Polled
	configfile->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(configfile);

	//	Attribute : distortionCorrection
	distortionCorrectionAttrib	*distortioncorrection = new distortionCorrectionAttrib();
	Tango::UserDefaultAttrProp	distortioncorrection_prop;
	distortioncorrection_prop.set_description("distortion correction.<br>\nWhen distortion correction is enabled :<br>\n- Large pixels are divided according to predefined denominator. <br>\n- The values of the pixels are rounded during division. <br>\n- If pixel value is saturated, the division is not applied.<br>");
	//	label	not set for distortionCorrection
	//	unit	not set for distortionCorrection
	//	standard_unit	not set for distortionCorrection
	//	display_unit	not set for distortionCorrection
	//	format	not set for distortionCorrection
	//	max_value	not set for distortionCorrection
	//	min_value	not set for distortionCorrection
	//	max_alarm	not set for distortionCorrection
	//	min_alarm	not set for distortionCorrection
	//	max_warning	not set for distortionCorrection
	//	min_warning	not set for distortionCorrection
	//	delta_t	not set for distortionCorrection
	//	delta_val	not set for distortionCorrection
	
	distortioncorrection->set_default_properties(distortioncorrection_prop);
	//	Not Polled
	distortioncorrection->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(distortioncorrection);

	//	Attribute : energyThreshold
	energyThresholdAttrib	*energythreshold = new energyThresholdAttrib();
	Tango::UserDefaultAttrProp	energythreshold_prop;
	energythreshold_prop.set_description("energy threshold in KeV.<br>\nThe photon is counted If the energy is above this threshold.<br>");
	//	label	not set for energyThreshold
	energythreshold_prop.set_unit("KeV");
	energythreshold_prop.set_standard_unit("KeV");
	energythreshold_prop.set_display_unit("KeV");
	energythreshold_prop.set_format("%6.2f");
	energythreshold_prop.set_max_value("300");
	energythreshold_prop.set_min_value("0");
	//	max_alarm	not set for energyThreshold
	//	min_alarm	not set for energyThreshold
	//	max_warning	not set for energyThreshold
	//	min_warning	not set for energyThreshold
	//	delta_t	not set for energyThreshold
	//	delta_val	not set for energyThreshold
	
	energythreshold->set_default_properties(energythreshold_prop);
	//	Not Polled
	energythreshold->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(energythreshold);

	//	Attribute : libraryVersion
	libraryVersionAttrib	*libraryversion = new libraryVersionAttrib();
	Tango::UserDefaultAttrProp	libraryversion_prop;
	libraryversion_prop.set_description("Version of the xsp library");
	//	label	not set for libraryVersion
	//	unit	not set for libraryVersion
	//	standard_unit	not set for libraryVersion
	//	display_unit	not set for libraryVersion
	//	format	not set for libraryVersion
	//	max_value	not set for libraryVersion
	//	min_value	not set for libraryVersion
	//	max_alarm	not set for libraryVersion
	//	min_alarm	not set for libraryVersion
	//	max_warning	not set for libraryVersion
	//	min_warning	not set for libraryVersion
	//	delta_t	not set for libraryVersion
	//	delta_val	not set for libraryVersion
	
	libraryversion->set_default_properties(libraryversion_prop);
	//	Not Polled
	libraryversion->set_disp_level(Tango::EXPERT);
	//	Not Memorized
	att_list.push_back(libraryversion);

	//	Attribute : highVoltage
	highVoltageAttrib	*highvoltage = new highVoltageAttrib();
	Tango::UserDefaultAttrProp	highvoltage_prop;
	highvoltage_prop.set_description("Value in V of the high Voltage");
	//	label	not set for highVoltage
	highvoltage_prop.set_unit("V");
	//	standard_unit	not set for highVoltage
	//	display_unit	not set for highVoltage
	//	format	not set for highVoltage
	//	max_value	not set for highVoltage
	//	min_value	not set for highVoltage
	//	max_alarm	not set for highVoltage
	//	min_alarm	not set for highVoltage
	//	max_warning	not set for highVoltage
	//	min_warning	not set for highVoltage
	//	delta_t	not set for highVoltage
	//	delta_val	not set for highVoltage
	
	highvoltage->set_default_properties(highvoltage_prop);
	//	Not Polled
	highvoltage->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(highvoltage);

	//	Attribute : humidity
	humidityAttrib	*humidity = new humidityAttrib();
	Tango::UserDefaultAttrProp	humidity_prop;
	humidity_prop.set_description("measured humidity in %");
	//	label	not set for humidity
	humidity_prop.set_unit("%");
	//	standard_unit	not set for humidity
	//	display_unit	not set for humidity
	//	format	not set for humidity
	//	max_value	not set for humidity
	//	min_value	not set for humidity
	//	max_alarm	not set for humidity
	//	min_alarm	not set for humidity
	//	max_warning	not set for humidity
	//	min_warning	not set for humidity
	//	delta_t	not set for humidity
	//	delta_val	not set for humidity
	
	humidity->set_default_properties(humidity_prop);
	//	Not Polled
	humidity->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(humidity);

	//	Attribute : temperature
	temperatureAttrib	*temperature = new temperatureAttrib();
	Tango::UserDefaultAttrProp	temperature_prop;
	temperature_prop.set_description("measured temperature in deg C");
	//	label	not set for temperature
	temperature_prop.set_unit("deg C");
	//	standard_unit	not set for temperature
	//	display_unit	not set for temperature
	//	format	not set for temperature
	//	max_value	not set for temperature
	//	min_value	not set for temperature
	//	max_alarm	not set for temperature
	//	min_alarm	not set for temperature
	//	max_warning	not set for temperature
	//	min_warning	not set for temperature
	//	delta_t	not set for temperature
	//	delta_val	not set for temperature
	
	temperature->set_default_properties(temperature_prop);
	//	Not Polled
	temperature->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(temperature);


	//	Create a list of static attributes
	create_static_attribute_list(get_class_attr()->get_attr_list());
	/*----- PROTECTED REGION ID(LambdaClass::attribute_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LambdaClass::attribute_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : LambdaClass::pipe_factory()
 *	Description : Create the pipe object(s)
 *                and store them in the pipe list
 */
//--------------------------------------------------------
void LambdaClass::pipe_factory()
{
	/*----- PROTECTED REGION ID(LambdaClass::pipe_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LambdaClass::pipe_factory_before
	/*----- PROTECTED REGION ID(LambdaClass::pipe_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LambdaClass::pipe_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : LambdaClass::command_factory()
 *	Description : Create the command object(s)
 *                and store them in the command list
 */
//--------------------------------------------------------
void LambdaClass::command_factory()
{
	/*----- PROTECTED REGION ID(LambdaClass::command_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LambdaClass::command_factory_before


	/*----- PROTECTED REGION ID(LambdaClass::command_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	LambdaClass::command_factory_after
}

//===================================================================
//	Dynamic attributes related methods
//===================================================================

//--------------------------------------------------------
/**
 * method : 		LambdaClass::create_static_attribute_list
 * description : 	Create the a list of static attributes
 *
 * @param	att_list	the ceated attribute list
 */
//--------------------------------------------------------
void LambdaClass::create_static_attribute_list(vector<Tango::Attr *> &att_list)
{
	for (unsigned long i=0 ; i<att_list.size() ; i++)
	{
		string att_name(att_list[i]->get_name());
		transform(att_name.begin(), att_name.end(), att_name.begin(), ::tolower);
		defaultAttList.push_back(att_name);
	}

	cout2 << defaultAttList.size() << " attributes in default list" << endl;

	/*----- PROTECTED REGION ID(LambdaClass::create_static_att_list) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LambdaClass::create_static_att_list
}


//--------------------------------------------------------
/**
 * method : 		LambdaClass::erase_dynamic_attributes
 * description : 	delete the dynamic attributes if any.
 *
 * @param	devlist_ptr	the device list pointer
 * @param	list of all attributes
 */
//--------------------------------------------------------
void LambdaClass::erase_dynamic_attributes(const Tango::DevVarStringArray *devlist_ptr, vector<Tango::Attr *> &att_list)
{
	Tango::Util *tg = Tango::Util::instance();

	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		Tango::DeviceImpl *dev_impl = tg->get_device_by_name(((string)(*devlist_ptr)[i]).c_str());
		Lambda *dev = static_cast<Lambda *> (dev_impl);

		vector<Tango::Attribute *> &dev_att_list = dev->get_device_attr()->get_attribute_list();
		vector<Tango::Attribute *>::iterator ite_att;
		for (ite_att=dev_att_list.begin() ; ite_att != dev_att_list.end() ; ++ite_att)
		{
			string att_name((*ite_att)->get_name_lower());
			if ((att_name == "state") || (att_name == "status"))
				continue;
			vector<string>::iterator ite_str = find(defaultAttList.begin(), defaultAttList.end(), att_name);
			if (ite_str == defaultAttList.end())
			{
				cout2 << att_name << " is a UNWANTED dynamic attribute for device " << (*devlist_ptr)[i] << endl;
				Tango::Attribute &att = dev->get_device_attr()->get_attr_by_name(att_name.c_str());
				dev->remove_attribute(att_list[att.get_attr_idx()], true, false);
				--ite_att;
			}
		}
	}
	/*----- PROTECTED REGION ID(LambdaClass::erase_dynamic_attributes) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	LambdaClass::erase_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Method      : LambdaClass::get_attr_object_by_name()
 *	Description : returns Tango::Attr * object found by name
 */
//--------------------------------------------------------
Tango::Attr *LambdaClass::get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname)
{
	vector<Tango::Attr *>::iterator it;
	for (it=att_list.begin() ; it<att_list.end() ; ++it)
		if ((*it)->get_name()==attname)
			return (*it);
	//	Attr does not exist
	return NULL;
}


/*----- PROTECTED REGION ID(LambdaClass::Additional Methods) ENABLED START -----*/

/*----- PROTECTED REGION END -----*/	//	LambdaClass::Additional Methods
} //	namespace

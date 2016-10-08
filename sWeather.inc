//------------------------------------------------------------------------------
// sWeather Include v1.0
// by sSiddhant
//
// This Include belongs to the sInclude Library by sSiddhant. This Include is
// created by sSiddhant and contains Functions and Callbacks related to Weather
//
// Functions:
// SetWeatherEx(weatherid)
// GetWeather()
//
// Callbacks:
// OnWeatherChange(weatherid)
//
// (c) Copyright 2016, sSiddhant. All Rights Reserved.
//
//------------------------------------------------------------------------------

#if defined _sWeather_included
  #endinput
#endif
#define _sWeather_included

#pragma library sInclude

//------------------------------------------------------------------------------
// SetWeatherEx(weatherid)
//
// This Functions is used to set the Weather of the Server and call
// OnWeatherChange Callback
//
// weatherid: The Id of the New Weather

stock SetWeatherEx(weatherid)
{
	SetWeather(weatherid);
	new weather = weatherid;
	CallLocalFunction(OnWeatherChange(weatherid));
}

//------------------------------------------------------------------------------
// GetWeather()
//
// This Functions is used to get the Current Weather of the Server

stock GetWeather()
{
	return weather;
}

//------------------------------------------------------------------------------
// OnWeatherChange(weatherid)
//
// This Callback is called when the Weather of the Server Changes using
// SetWeatherEx Function

forward OnWeatherChange(weatherid);
public OnWeatherChange(weatherid)
{
	return 1;
}

//------------------------------------------------------------------------------

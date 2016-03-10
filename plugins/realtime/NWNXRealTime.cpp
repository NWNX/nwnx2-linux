#include "stdafx.h"
#include "NWNXRealTime.h"

NWNXRealTime::NWNXRealTime()
{
  loadtime = wxDateTime::Now();
}

NWNXRealTime::~NWNXRealTime()
{
  OnRelease();
}

char* NWNXRealTime::OnRequest(char *gameObject, char* Request, char* Parameters)
{
  wxString wxRequest(Request);
  if (wxRequest.IsEmpty() || wxRequest.IsNull())
    Log("* Missing Request [%s].\n", wxRequest);
  else
  {
    wxDateTime now = wxDateTime::Now();
    wxString result = wxEmptyString;
	if      (wxRequest == wxT("DATE"))        result = wxString::Format("%s",now.FormatISODate());
	else if (wxRequest == wxT("TIME"))        result = wxString::Format("%s",now.FormatISOTime());
	else if (wxRequest == wxT("DATETIME"))    result = wxString::Format("%s %s",now.FormatISODate(),now.FormatISOTime());
	else if (wxRequest == wxT("LOADTIME"))    result = wxString::Format("%s %s",loadtime.FormatISODate(), loadtime.FormatISOTime());
	else if (wxRequest == wxT("UPTIME"))      result = wxString::Format("%s",now.Subtract(loadtime).Format());
	else if (wxRequest == wxT("DAYFULL"))     result = wxString::Format("%s",wxDateTime::GetWeekDayName(now.GetWeekDay(),wxDateTime::Name_Full));
	else if (wxRequest == wxT("DAYSHORT"))    result = wxString::Format("%s",wxDateTime::GetWeekDayName(now.GetWeekDay(),wxDateTime::Name_Abbr));
	else if (wxRequest == wxT("MONTHFULL"))   result = wxString::Format("%s",wxDateTime::GetMonthName(now.GetMonth(),wxDateTime::Name_Full));
	else if (wxRequest == wxT("MONTHSHORT"))  result = wxString::Format("%s",wxDateTime::GetMonthName(now.GetMonth(),wxDateTime::Name_Abbr));
	else if (wxRequest == wxT("YEAR"))        result = wxString::Format("%d",now.GetYear());
	else if (wxRequest == wxT("MONTH"))       result = wxString::Format("%d",now.GetMonth()+1);//ZeroBased, so add 1
	else if (wxRequest == wxT("DAY"))         result = wxString::Format("%d",now.GetDay());
	else if (wxRequest == wxT("HOUR"))        result = wxString::Format("%d",now.GetHour());
	else if (wxRequest == wxT("MINUTE"))      result = wxString::Format("%d",now.GetMinute());
	else if (wxRequest == wxT("SECOND"))      result = wxString::Format("%d",now.GetSecond());
	else if (wxRequest == wxT("MILLISECOND")) result = wxString::Format("%d",now.GetMillisecond());
	else if (wxRequest == wxT("UPDAYS"))      result = wxString::Format("%d",now.Subtract(loadtime).GetDays());
	else if (wxRequest == wxT("UPHOURS"))     result = wxString::Format("%d",now.Subtract(loadtime).GetHours());
	else if (wxRequest == wxT("UPMINUTES"))   result = wxString::Format("%d",now.Subtract(loadtime).GetMinutes());
	else if (wxRequest == wxT("UPSECONDS"))   result = wxString::Format("%d",now.Subtract(loadtime).GetSeconds());
	else if (wxRequest == wxT("UPMILLISECONDS"))   result = wxString::Format("%d",now.Subtract(loadtime).GetMilliseconds());
	else Log("* Unknown Request [%s].\n", wxRequest);
	if (!(result.IsEmpty() || result.IsNull()))
	{
	  Log("o %s: = %s\n", wxRequest, result);
	  sprintf_s(Parameters, strlen(Parameters), "%s", result);
	}
  }

  return NULL;
}

bool NWNXRealTime::OnCreate(const char* LogDir)
{
	// call the base class function
	char log[MAX_PATH];
	sprintf (log, "%s\\nwnx_realtime.log", LogDir);
	if (!NWNXBase::OnCreate(log)) return false;
	WriteLogHeader();
	return true;
}

bool NWNXRealTime::OnRelease()
{
  wxDateTime now(wxDateTime::Now());
  Log("o Shutting down [%s %s]\n",now.FormatISODate(),now.FormatISOTime());
  // call base class function
  return NWNXBase::OnRelease();
}

void NWNXRealTime::WriteLogHeader()
{
	fprintf(m_fFile, "NWNX^2 RealTime plugin v1.2\n");
	fprintf(m_fFile, "(c) 2007 by Rob Lobbe (Gryphyn)\n");
	fprintf(m_fFile, "visit us at http://www.nwnx.org\n\n");
	fprintf(m_fFile, "o Started [%s %s]\n", loadtime.FormatISODate(), loadtime.FormatISOTime());
}
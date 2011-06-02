package org.nwnx.nwnx2.jvm;

public interface ResManListener {
	/**
	 * Gets called when NWServer wants to load a resource.
	 * Return null to not handle the request, and pass it
	 * on to other listeners or NWServer. Unhandled requests
	 * will be handled by nwserver itself by searching haks and base
	 * resources.
	 * @param resRef the resRef to load (for example: "nw_c2_default9.ncs")
	 * @return the raw resource data, or null
	 */
	public byte[] demandRes(String resRef);
}

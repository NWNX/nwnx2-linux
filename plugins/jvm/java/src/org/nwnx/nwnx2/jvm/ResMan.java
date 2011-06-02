package org.nwnx.nwnx2.jvm;

import java.util.LinkedList;
import java.util.List;

public class ResMan {
	private static List<ResManListener> handlers =
		new LinkedList<ResManListener>();

	public static void addResManListener(ResManListener h) {
		handlers.add(h);
	}

	private ResMan() {
	}

	@SuppressWarnings("unused")
	private static byte[] demandRes(String resRef) {
		byte[] ret = null;
		for (ResManListener h : handlers)
			if (null != (ret = h.demandRes(resRef)))
				return ret;

		return null;
	}
}

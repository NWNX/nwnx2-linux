import org.nwnx.nwnx2.jvm.*;

public class EventExample implements SchedulerListener {
	public void postFlushQueues(int remainingTokens) {}
	public void missedToken(NWObject objSelf, String token) {}
	public void context(NWObject objSelf) {}
	
	public void event(NWObject objSelf, String event) {
		NWScript.sendMessageToAllDMs("Event from Java: " + event + " on OBJECT_SELF = " + objSelf.oid());
	}
}

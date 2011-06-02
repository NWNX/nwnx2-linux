import org.nwnx.nwnx2.jvm.*;

public class InitExample {

	private static EventExample e = new EventExample();

	/**
	 * Called before any configured classes and methods
	 * are looked up in jni. You can use this to setup
	 * class pathes and load plugins/custom classes that
	 * are required to start up.
	*/
	private static void setup() {
	}

	/**
	 * Called just before continuing startup inside NWNX.
	 * Use this to do your usual initialisation - do not
	 * use setup() for that.
	*/
	private static void init() {
		Scheduler.addSchedulerListener(e);

		/* Add some default handlers that don't do any
		 * custom wrapping at all.
		 */
		NWObject.registerObjectHandler(new NWObject.ObjectHandler() {
			public NWObject handleObjectClass(NWObject obj, boolean valid,
					int objectType, String resRef, String tag) {
				return obj;
			}
		});
		NWEffect.registerEffectHandler(new NWEffect.EffectHandler() {
			public NWEffect handleEffectClass(NWEffect eff) {
				return eff;
			}
		});
		NWItemProperty.registerItemPropertyHandler(new NWItemProperty.ItemPropertyHandler() {
			public NWItemProperty handleItemPropertyClass(NWItemProperty prp) {
				return prp;
			}
		});

	}

	/**
	 * Called just before terminating the JVM. No NWN context
	 * is available. Not called on errors or crashes.
	 */
	private static void shutdown() {
	}
}

module NWScriptInternal
    module Scheduler
        @@store = {}

        def self.assign obj, &code
            @@store[obj] ||= []
            @@store[obj] << code # this auto-serializes &code into a lambda and binds all variables
        end

        def self.flush
            @@store.keys.each do |oid|
                NWScript.ExecuteScript("nwnx_ruby_hnd", oid)
            end
        end

        # you need to call this when "handler" executes
        def self.onCallback
            @@store[$OBJECT_SELF].each do |lambda|
                lambda.call()
            end
            @@store.delete($OBJECT_SELF)
        end
    end
end

module NWScript
    def AssignCommand oPC, &code
        NWScriptInternal::Scheduler.assign oPC, &code
        NWScriptInternal::Scheduler.flush
    end
end
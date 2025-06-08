package com.bearmod.core.hooks;

import java.util.concurrent.atomic.AtomicLong;

/**
 * Information container for active hooks
 * Stores metadata about hooked functions including statistics and status
 */
public class HookInfo {
    private final String libraryName;
    private final String functionName;
    private final HookType hookType;
    private final long creationTime;
    private final AtomicLong callCount;
    private final AtomicLong lastCallTime;
    private volatile boolean isActive;
    private volatile String lastError;
    
    /**
     * Constructor for HookInfo
     * 
     * @param libraryName Name of the library containing the hooked function
     * @param functionName Name of the hooked function
     * @param hookType Type of hook applied
     */
    public HookInfo(String libraryName, String functionName, HookType hookType) {
        this.libraryName = libraryName;
        this.functionName = functionName;
        this.hookType = hookType;
        this.creationTime = System.currentTimeMillis();
        this.callCount = new AtomicLong(0);
        this.lastCallTime = new AtomicLong(0);
        this.isActive = true;
        this.lastError = null;
    }
    
    /**
     * Get the library name
     * 
     * @return Library name
     */
    public String getLibraryName() {
        return libraryName;
    }
    
    /**
     * Get the function name
     * 
     * @return Function name
     */
    public String getFunctionName() {
        return functionName;
    }
    
    /**
     * Get the hook type
     * 
     * @return Hook type
     */
    public HookType getHookType() {
        return hookType;
    }
    
    /**
     * Get the creation time
     * 
     * @return Creation timestamp in milliseconds
     */
    public long getCreationTime() {
        return creationTime;
    }
    
    /**
     * Get the number of times this hook has been called
     * 
     * @return Call count
     */
    public long getCallCount() {
        return callCount.get();
    }
    
    /**
     * Get the timestamp of the last call
     * 
     * @return Last call timestamp in milliseconds
     */
    public long getLastCallTime() {
        return lastCallTime.get();
    }
    
    /**
     * Check if the hook is currently active
     * 
     * @return true if active, false otherwise
     */
    public boolean isActive() {
        return isActive;
    }
    
    /**
     * Set the active status of the hook
     * 
     * @param active New active status
     */
    public void setActive(boolean active) {
        this.isActive = active;
    }
    
    /**
     * Get the last error message
     * 
     * @return Last error message, or null if no error
     */
    public String getLastError() {
        return lastError;
    }
    
    /**
     * Set the last error message
     * 
     * @param error Error message
     */
    public void setLastError(String error) {
        this.lastError = error;
    }
    
    /**
     * Record a function call
     * Updates call count and last call time
     */
    public void recordCall() {
        callCount.incrementAndGet();
        lastCallTime.set(System.currentTimeMillis());
    }
    
    /**
     * Get the hook identifier
     * 
     * @return Unique identifier for this hook
     */
    public String getHookId() {
        return libraryName + ":" + functionName;
    }
    
    /**
     * Get the age of this hook in milliseconds
     * 
     * @return Age in milliseconds
     */
    public long getAge() {
        return System.currentTimeMillis() - creationTime;
    }
    
    /**
     * Get the time since last call in milliseconds
     * 
     * @return Time since last call, or -1 if never called
     */
    public long getTimeSinceLastCall() {
        long lastCall = lastCallTime.get();
        if (lastCall == 0) {
            return -1; // Never called
        }
        return System.currentTimeMillis() - lastCall;
    }
    
    /**
     * Get call frequency (calls per second)
     * 
     * @return Calls per second, or 0 if no calls or age is 0
     */
    public double getCallFrequency() {
        long age = getAge();
        if (age == 0 || callCount.get() == 0) {
            return 0.0;
        }
        return (double) callCount.get() / (age / 1000.0);
    }
    
    /**
     * Check if this hook has been called recently
     * 
     * @param thresholdMs Threshold in milliseconds
     * @return true if called within the threshold, false otherwise
     */
    public boolean isRecentlyActive(long thresholdMs) {
        long timeSinceLastCall = getTimeSinceLastCall();
        return timeSinceLastCall >= 0 && timeSinceLastCall <= thresholdMs;
    }
    
    /**
     * Get hook status summary
     * 
     * @return Status summary string
     */
    public String getStatusSummary() {
        StringBuilder status = new StringBuilder();
        status.append("Hook: ").append(getHookId()).append("\n");
        status.append("Type: ").append(hookType.getDisplayName()).append("\n");
        status.append("Active: ").append(isActive).append("\n");
        status.append("Calls: ").append(callCount.get()).append("\n");
        status.append("Age: ").append(getAge() / 1000).append("s\n");
        
        if (callCount.get() > 0) {
            status.append("Frequency: ").append(String.format("%.2f", getCallFrequency())).append(" calls/s\n");
            status.append("Last Call: ").append(getTimeSinceLastCall() / 1000).append("s ago\n");
        }
        
        if (lastError != null) {
            status.append("Last Error: ").append(lastError).append("\n");
        }
        
        return status.toString();
    }
    
    /**
     * Get detailed hook information
     * 
     * @return Detailed information string
     */
    public String getDetailedInfo() {
        StringBuilder info = new StringBuilder();
        info.append("=== Hook Information ===\n");
        info.append("Library: ").append(libraryName).append("\n");
        info.append("Function: ").append(functionName).append("\n");
        info.append("Type: ").append(hookType.getDisplayName()).append("\n");
        info.append("Description: ").append(hookType.getDescription()).append("\n");
        info.append("Priority: ").append(hookType.getPriority()).append("\n");
        info.append("Created: ").append(new java.util.Date(creationTime)).append("\n");
        info.append("Active: ").append(isActive).append("\n");
        info.append("\n=== Statistics ===\n");
        info.append("Total Calls: ").append(callCount.get()).append("\n");
        info.append("Age: ").append(getAge() / 1000).append(" seconds\n");
        
        if (callCount.get() > 0) {
            info.append("Call Frequency: ").append(String.format("%.2f", getCallFrequency())).append(" calls/second\n");
            info.append("Last Call: ").append(new java.util.Date(lastCallTime.get())).append("\n");
            info.append("Time Since Last Call: ").append(getTimeSinceLastCall() / 1000).append(" seconds\n");
        } else {
            info.append("Never called\n");
        }
        
        if (lastError != null) {
            info.append("\n=== Error Information ===\n");
            info.append("Last Error: ").append(lastError).append("\n");
        }
        
        return info.toString();
    }
    
    @Override
    public String toString() {
        return String.format("HookInfo{%s, type=%s, active=%s, calls=%d}", 
                           getHookId(), hookType, isActive, callCount.get());
    }
    
    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        
        HookInfo hookInfo = (HookInfo) obj;
        return libraryName.equals(hookInfo.libraryName) && 
               functionName.equals(hookInfo.functionName) &&
               hookType == hookInfo.hookType;
    }
    
    @Override
    public int hashCode() {
        return getHookId().hashCode() + hookType.hashCode();
    }
}

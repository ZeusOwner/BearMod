pluginManagement {
    repositories {
        gradlePluginPortal()
        google()
        mavenCentral()
    }
    plugins {
        id("org.gradle.toolchains.foojay-resolver-convention") version "0.8.0"
       // id("com.google.firebase.crashlytics") version "3.0.3"
    }
}

dependencyResolutionManagement {
    repositoriesMode.set(RepositoriesMode.FAIL_ON_PROJECT_REPOS)
    repositories {
        google()
        mavenCentral()
        maven { url = uri("https://jitpack.io") }
    }
}

include(":app")
include(":bearmod")

rootProject.name = "Bear-Loader"

// Configure BearMod module path
project(":bearmod").projectDir = file("modules/bearmod")
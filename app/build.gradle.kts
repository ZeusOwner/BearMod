plugins {
    alias(libs.plugins.android.application)
}

android {
    compileSdk = libs.versions.compileSdk.get().toInt()
    namespace = "com.bearmod"

    defaultConfig {
        applicationId = "com.bearmod"
        minSdk = libs.versions.minSdk.get().toInt()
        targetSdk = libs.versions.targetSdk.get().toInt()
        versionCode = libs.versions.versionCode.get().toInt()
        versionName = libs.versions.versionName.get()
        testInstrumentationRunner = "androidx.test.runner.AndroidJUnitRunner"

        ndk {
            abiFilters += listOf("arm64-v8a") // Add more ABIs if needed
        }

        externalNativeBuild {
            ndkBuild {
                arguments += listOf("-j8")
                abiFilters += listOf("arm64-v8a")
            }
        }
    }

    signingConfigs {
        create("release") {
            // These will be set by CI/CD or local.properties
            storeFile = file(findProperty("RELEASE_STORE_FILE") as String? ?: "release.keystore")
            storePassword = findProperty("RELEASE_STORE_PASSWORD") as String? ?: ""
            keyAlias = findProperty("RELEASE_KEY_ALIAS") as String? ?: ""
            keyPassword = findProperty("RELEASE_KEY_PASSWORD") as String? ?: ""
        }

        getByName("debug") {
            // Optional: Configure debug signing if needed
            // For local development, you can uncomment and set these:
            // storeFile = file("debug.keystore")
            // storePassword = "android"
            // keyAlias = "androiddebugkey"
            // keyPassword = "android"
        }
    }

    lint {
        baseline = file("lint-baseline.xml")
        disable += listOf("InvalidPackage", "MissingTranslation", "NewApi", "UnusedResources", "IconMissingDensityFolder")
        abortOnError = false
    }

    buildTypes {
        getByName("debug") {
            isDebuggable = true
            isMinifyEnabled = false
            applicationIdSuffix = ".debug"
            versionNameSuffix = "-debug"
        }

        getByName("release") {
            isMinifyEnabled = false
            proguardFiles(
                getDefaultProguardFile("proguard-android-optimize.txt"),
                "proguard-rules.pro"
            )
            // Use release signing config if available, otherwise debug
            signingConfig = if (hasProperty("RELEASE_STORE_FILE")) {
                signingConfigs.getByName("release")
            } else {
                logger.warn("[BearMod] WARNING: Release signing properties not found. Using debug signing config for release build. Please configure RELEASE_STORE_FILE and related properties in local.properties for secure release signing.")
                signingConfigs.getByName("debug")
            }
        }
    }



    tasks.withType<JavaCompile>().configureEach {
        options.compilerArgs.addAll(listOf("-Xlint:unchecked", "-Xlint:deprecation"))
    }

    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_17
        targetCompatibility = JavaVersion.VERSION_17
    }

    externalNativeBuild {
        ndkBuild {
            path = file("src/main/jni/Android.mk")
        }
    }

    ndkVersion = libs.versions.ndk.get()
}

dependencies {

    implementation(fileTree(mapOf("dir" to "libs", "include" to listOf("*.jar"))))

    // BearMod Integration
    implementation(project(":bearmod"))

    // AndroidX UI Libraries
    implementation(libs.bundles.androidx.ui)
    implementation(libs.material)

    // Kotlin Coroutines for async operations
    implementation("org.jetbrains.kotlinx:kotlinx-coroutines-android:1.7.3")
    implementation("androidx.lifecycle:lifecycle-runtime-ktx:2.7.0")

    // Networking
    implementation(libs.bundles.networking)

    // Unit Testing
    testImplementation(libs.bundles.testing.unit)

    // Android Testing
    androidTestImplementation(libs.bundles.testing.android)
}
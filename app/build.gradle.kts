plugins {
    id("com.android.application")
}

android {
    compileSdk = libs.versions.compileSdk.get().toInt()
    namespace = "com.bearmod"

    defaultConfig {
        applicationId = "com.bearmod"
        minSdk = libs.versions.minSdk.get().toInt()
        //noinspection OldTargetApi
        targetSdk = libs.versions.targetSdk.get().toInt()
        versionCode = libs.versions.versionCode.get().toInt()
        versionName = libs.versions.versionName.get()
        testInstrumentationRunner = "androidx.test.runner.AndroidJUnitRunner"
        ndk {
            //noinspection ChromeOsAbiSupport
            abiFilters += "arm64-v8a"
        }
    }

    lint {
        baseline = file("lint-baseline.xml")
        disable += listOf("InvalidPackage", "MissingTranslation")
    }

    buildTypes {
        release {
            isMinifyEnabled = false
            proguardFiles(getDefaultProguardFile("proguard-android-optimize.txt"), "proguard-rules.pro")
            signingConfig = signingConfigs.getByName("debug")
        }
    }

    tasks.withType<JavaCompile>().configureEach {
        options.compilerArgs.addAll(listOf("-Xlint:unchecked", "-Xlint:deprecation"))
    }

    externalNativeBuild {
        ndkBuild {
            path("src/main/jni/Android.mk")
        }
    }

    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_17
        targetCompatibility = JavaVersion.VERSION_17
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
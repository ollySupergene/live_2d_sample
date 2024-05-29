package com.yunho.live2d;

import android.app.Activity;
import android.content.Context;

import java.io.IOException;
import java.io.InputStream;

public class JniBridgeJava {
    // Native -----------------------------------------------------------------

    public static native void nativeOnStart();

    public static native void nativeOnPause();

    public static native void nativeOnStop();

    public static native void nativeOnDestroy();

    public static native void nativeOnSurfaceCreated();

    public static native void nativeOnSurfaceChanged(int width, int height);

    public static native void nativeOnDrawFrame();

    public static native void nativeOnTouchesBegan(float pointX, float pointY);

    public static native void nativeOnTouchesEnded(float pointX, float pointY);

    public static native void nativeOnTouchesMoved(float pointX, float pointY);

    // Java -----------------------------------------------------------------

    public static void SetContext(Context context) {
        JniBridgeJava.context = context;
    }

    public static void SetActivityInstance(Activity activity) {
        activityInstance = activity;
    }

    public static String[] GetAssetList(String dirPath) {
        try {
            return context.getAssets().list(dirPath);
        } catch (IOException e) {
            e.printStackTrace();
            return new String[0];
        }
    }

    public static byte[] LoadFile(String filePath) {
        InputStream fileData = null;
        try {
            fileData = context.getAssets().open(filePath);
            int fileSize = fileData.available();
            byte[] fileBuffer = new byte[fileSize];
            fileData.read(fileBuffer, 0, fileSize);
            return fileBuffer;
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        } finally {
            try {
                if (fileData != null) {
                    fileData.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public static void MoveTaskToBack() {
        activityInstance.moveTaskToBack(true);
    }

    private static Activity activityInstance;
    private static Context context;
    private static final String LIBRARY_NAME = "live2d";

    static {
        System.loadLibrary(LIBRARY_NAME);
    }
}

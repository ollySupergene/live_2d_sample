package com.yunho.mytest

import android.opengl.GLSurfaceView
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.runtime.Composable
import androidx.compose.runtime.LaunchedEffect
import androidx.compose.runtime.remember
import androidx.compose.ui.Modifier
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.viewinterop.AndroidView
import com.yunho.live2d.GLRenderer
import com.yunho.live2d.JniBridgeJava

@Composable
fun Live2dScreen() {
    val context = LocalContext.current
    val glRenderer = remember {
        GLRenderer()
    }
    val glSurfaceView = remember {
        GLSurfaceView(context).apply {
            setEGLContextClientVersion(2)
            setRenderer(glRenderer)
        }
    }

    LaunchedEffect(Unit) {
        JniBridgeJava.SetContext(context)
    }

    AndroidView(
        modifier = Modifier.fillMaxSize(),
        factory = {
            glSurfaceView
        },
        update = {

        }
    )
}

@file:JvmName("AssetUtils")

package com.sit.uapki.android.utils

import android.content.Context
import android.util.Log
import java.io.File
import java.io.FileOutputStream
import java.io.IOException

@Throws(IOException::class)
fun copyAssets(context: Context, destPath: String) {
    copyAssetDir(context, "", destPath)
}

@Throws(IOException::class)
fun copyAssetDir(context: Context, srcPath: String, destPath: String) {
    walkAssetDir(context, srcPath) {
        copyAssetFile(context, it, "$destPath/$it")
    }
}

@Throws(IOException::class)
fun copyAssetFile(context: Context, srcPath: String, destPath: String): File {
    val destFile = File(destPath)
    File(destFile.parent!!).mkdirs()
    destFile.createNewFile()

    context.assets.open(srcPath).use { src ->
        FileOutputStream(destFile).use { dest ->
            Log.d("Assets", "Copying asset from \"$srcPath\" to \"$destPath\"...")
            src.copyTo(dest)
        }
    }

    return destFile
}

@Throws(IOException::class)
private fun walkAssetDir(context: Context, srcPath: String, callback: ((String) -> Unit)) {
    val children = context.assets.list(srcPath) ?: return
    if (children.isNotEmpty()) {
        children.forEach {
            walkAssetDir(context, "$srcPath/$it".trim('/'), callback)
        }
    } else {
        callback(srcPath)
    }
}

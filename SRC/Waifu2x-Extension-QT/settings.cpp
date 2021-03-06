﻿/*
    Copyright (C) 2020  Aaron Feng

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

    My Github homepage: https://github.com/AaronFeng753
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
/*
保存设置
删除原设置文件,保存设置
*/
int MainWindow::Settings_Save()
{
    QString settings_ini = Current_Path+"/settings.ini";
    QFile::remove(settings_ini);
    //=================
    QSettings *configIniWrite = new QSettings(settings_ini, QSettings::IniFormat);
    configIniWrite->setIniCodec(QTextCodec::codecForName("UTF-8"));
    //================= 添加警告 =========================
    configIniWrite->setValue("/Warning/EN", "Do not modify this file! It may cause the program to crash! If problems occur after the modification, delete this article and restart the program.");
    //==================== 存储版本识别 ==================================
    configIniWrite->setValue("/settings/VERSION", VERSION);
    //=======  存储放大值和降噪值  =================================
    configIniWrite->setValue("/settings/ImageScaleRatio", ui->spinBox_ScaleRatio_image->value());
    configIniWrite->setValue("/settings/GIFScaleRatio", ui->spinBox_ScaleRatio_gif->value());
    configIniWrite->setValue("/settings/VideoScaleRatio", ui->spinBox_ScaleRatio_video->value());
    configIniWrite->setValue("/settings/ImageDenoiseLevel", ui->spinBox_DenoiseLevel_image->value());
    configIniWrite->setValue("/settings/GIFDenoiseLevel", ui->spinBox_DenoiseLevel_gif->value());
    configIniWrite->setValue("/settings/VideoDenoiseLevel", ui->spinBox_DenoiseLevel_video->value());
    //============ 存储自定义宽度和高度及设置 ============================
    configIniWrite->setValue("/settings/CustResWidth", ui->spinBox_CustRes_width->value());
    configIniWrite->setValue("/settings/CustResHeight", ui->spinBox_CustRes_height->value());
    configIniWrite->setValue("/settings/CustResAspectRatioMode", ui->comboBox_AspectRatio_custRes->currentIndex());
    //============ 存储线程数量 ====================================
    configIniWrite->setValue("/settings/ImageThreadNum", ui->spinBox_ThreadNum_image->value());
    configIniWrite->setValue("/settings/GIFThreadNumInternal", ui->spinBox_ThreadNum_gif_internal->value());
    configIniWrite->setValue("/settings/VideoThreadNumInternal", ui->spinBox_ThreadNum_video_internal->value());
    //================== 存储引擎设置 =========================
    configIniWrite->setValue("/settings/ImageEngine", ui->comboBox_Engine_Image->currentIndex());
    configIniWrite->setValue("/settings/GIFEngine", ui->comboBox_Engine_GIF->currentIndex());
    configIniWrite->setValue("/settings/VideoEngine", ui->comboBox_Engine_Video->currentIndex());
    configIniWrite->setValue("/settings/ImageStyle", ui->comboBox_ImageStyle->currentIndex());
    configIniWrite->setValue("/settings/ModelVulkan", ui->comboBox_model_vulkan->currentIndex());
    configIniWrite->setValue("/settings/TileSize", ui->spinBox_TileSize->value());
    configIniWrite->setValue("/settings/BlockSizeConverter", ui->spinBox_BlockSize_converter->value());
    configIniWrite->setValue("/settings/DisableGPUConverter", ui->checkBox_DisableGPU_converter->isChecked());
    configIniWrite->setValue("/settings/ForceOpenCLConverter", ui->checkBox_ForceOpenCL_converter->isChecked());
    configIniWrite->setValue("/settings/TTAVulkan", ui->checkBox_TTA_vulkan->isChecked());
    configIniWrite->setValue("/settings/TTAConverter", ui->checkBox_TTA_converter->isChecked());
    configIniWrite->setValue("/settings/TTA_SRMD", ui->checkBox_TTA_srmd->isChecked());
    configIniWrite->setValue("/settings/TileSize_SRMD", ui->spinBox_TileSize_srmd->value());
    configIniWrite->setValue("/settings/Version_Waifu2xNCNNVulkan", ui->comboBox_version_Waifu2xNCNNVulkan->currentIndex());
    //===
    configIniWrite->setValue("/settings/TTA_Waifu2xCaffe", ui->checkBox_TTA_Waifu2xCaffe->isChecked());
    configIniWrite->setValue("/settings/Model_2D_Waifu2xCaffe", ui->comboBox_Model_2D_Waifu2xCaffe->currentIndex());
    configIniWrite->setValue("/settings/Model_3D_Waifu2xCaffe", ui->comboBox_Model_3D_Waifu2xCaffe->currentIndex());
    configIniWrite->setValue("/settings/ProcessMode_Waifu2xCaffe", ui->comboBox_ProcessMode_Waifu2xCaffe->currentIndex());
    configIniWrite->setValue("/settings/BatchSize_Waifu2xCaffe", ui->spinBox_BatchSize_Waifu2xCaffe->value());
    configIniWrite->setValue("/settings/GPUID_Waifu2xCaffe", ui->spinBox_GPUID_Waifu2xCaffe->value());
    configIniWrite->setValue("/settings/SplitSize_Waifu2xCaffe", ui->spinBox_SplitSize_Waifu2xCaffe->value());
    //===
    configIniWrite->setValue("/settings/checkBox_TTA_RealsrNCNNVulkan", ui->checkBox_TTA_RealsrNCNNVulkan->isChecked());
    configIniWrite->setValue("/settings/comboBox_Model_RealsrNCNNVulkan", ui->comboBox_Model_RealsrNCNNVulkan->currentIndex());
    configIniWrite->setValue("/settings/spinBox_TileSize_RealsrNCNNVulkan", ui->spinBox_TileSize_RealsrNCNNVulkan->value());
    //GPU ID List
    configIniWrite->setValue("/settings/CurrentGPUID_Waifu2xNCNNVulkan", ui->comboBox_GPUID->currentIndex());
    configIniWrite->setValue("/settings/Available_GPUID_Waifu2xNCNNVulkan", Available_GPUID);
    configIniWrite->setValue("/settings/comboBox_GPUID_RealsrNCNNVulkan", ui->comboBox_GPUID_RealsrNCNNVulkan->currentIndex());
    configIniWrite->setValue("/settings/Available_GPUID_Realsr_ncnn_vulkan", Available_GPUID_Realsr_ncnn_vulkan);
    configIniWrite->setValue("/settings/comboBox_TargetProcessor_converter", ui->comboBox_TargetProcessor_converter->currentIndex());
    configIniWrite->setValue("/settings/Available_ProcessorList_converter", Available_ProcessorList_converter);
    configIniWrite->setValue("/settings/comboBox_GPUID_srmd", ui->comboBox_GPUID_srmd->currentIndex());
    configIniWrite->setValue("/settings/Available_GPUID_srmd", Available_GPUID_srmd);
    //================== 存储 扩展名 =================================
    configIniWrite->setValue("/settings/ImageEXT", ui->Ext_image->text());
    configIniWrite->setValue("/settings/VideoEXT", ui->Ext_video->text());
    //=================== 存储 杂项设置 =================================
    configIniWrite->setValue("/settings/checkBox_custres_isAll", ui->checkBox_custres_isAll->isChecked());
    configIniWrite->setValue("/settings/SaveAsJPG", ui->checkBox_SaveAsJPG->isChecked());
    configIniWrite->setValue("/settings/CompressJPG", ui->checkBox_CompressJPG->isChecked());
    configIniWrite->setValue("/settings/DelOriginal", ui->checkBox_DelOriginal->isChecked());
    configIniWrite->setValue("/settings/Move2RecycleBin", ui->checkBox_Move2RecycleBin->isChecked());
    configIniWrite->setValue("/settings/OptGIF", ui->checkBox_OptGIF->isChecked());
    configIniWrite->setValue("/settings/NFSound", ui->checkBox_NfSound->isChecked());
    configIniWrite->setValue("/settings/ReProFinFiles", ui->checkBox_ReProcFinFiles->isChecked());
    configIniWrite->setValue("/settings/ShowInterPro", ui->checkBox_ShowInterPro->isChecked());
    configIniWrite->setValue("/settings/UpdatePopup", ui->checkBox_UpdatePopup->isChecked());
    configIniWrite->setValue("/settings/FileListAutoScroll", ui->checkBox_FileListAutoSlide->isChecked());
    configIniWrite->setValue("/settings/AutoSaveSettings", ui->checkBox_AutoSaveSettings->isChecked());
    configIniWrite->setValue("/settings/AlwaysHideSettings", ui->checkBox_AlwaysHideSettings->isChecked());
    configIniWrite->setValue("/settings/AlwaysHideTextBrowser", ui->checkBox_AlwaysHideTextBrowser->isChecked());
    configIniWrite->setValue("/settings/JPGCompressedQuality", ui->spinBox_JPGCompressedQuality->value());
    configIniWrite->setValue("/settings/ScanSubFolders", ui->checkBox_ScanSubFolders->isChecked());
    configIniWrite->setValue("/settings/InteractiveFileList", ui->checkBox_FileList_Interactive->isChecked());
    configIniWrite->setValue("/settings/RetryTimes", ui->spinBox_retry->value());
    configIniWrite->setValue("/settings/AutoDetectAlphaChannel", ui->checkBox_AutoDetectAlphaChannel->isChecked());
    configIniWrite->setValue("/settings/PromptWhenExit", ui->checkBox_PromptWhenExit->isChecked());
    configIniWrite->setValue("/settings/KeepVideoCache", ui->checkBox_KeepVideoCache->isChecked());
    //===
    configIniWrite->setValue("/settings/ProcessVideoBySegment", ui->checkBox_ProcessVideoBySegment->isChecked());
    configIniWrite->setValue("/settings/SegmentDuration", ui->spinBox_SegmentDuration->value());
    //=====
    configIniWrite->setValue("/settings/AudioDenoise", ui->checkBox_AudioDenoise->isChecked());
    configIniWrite->setValue("/settings/AudioDenoiseLevel", ui->doubleSpinBox_AudioDenoiseLevel->value());
    //=====
    configIniWrite->setValue("/settings/checkBox_PreProcessImage", ui->checkBox_PreProcessImage->isChecked());
    //===================== 存储 textbrowser 设置 =====================
    configIniWrite->setValue("/settings/TextBrowserFontSize", ui->spinBox_textbrowser_fontsize->value());
    //===================== 存储语言设置 ================================
    configIniWrite->setValue("/settings/Language", ui->comboBox_language->currentIndex());
    //================== 存储全局字体 =========================
    configIniWrite->setValue("/settings/GlobalFontSize", ui->spinBox_GlobalFontSize->value());
    configIniWrite->setValue("/settings/CustFont", ui->fontComboBox_CustFont->currentFont());
    configIniWrite->setValue("/settings/CustFont_isEnabled", ui->checkBox_isCustFontEnable->isChecked());
    //=================== 存储视频设置 ===========================
    configIniWrite->setValue("/settings/VideoSettingsIsEnabled", ui->checkBox_videoSettings_isEnabled->isChecked());
    configIniWrite->setValue("/settings/EncoderVideo", ui->lineEdit_encoder_vid->text());
    configIniWrite->setValue("/settings/EncoderAudio", ui->lineEdit_encoder_audio->text());
    configIniWrite->setValue("/settings/PixelFormat", ui->lineEdit_pixformat->text());
    configIniWrite->setValue("/settings/BitrateVideo", ui->spinBox_bitrate_vid->value());
    configIniWrite->setValue("/settings/BitrateAudio", ui->spinBox_bitrate_audio->value());
    configIniWrite->setValue("/settings/ExtraCommandOutput", ui->lineEdit_ExCommand_output->text());
    //===
    configIniWrite->setValue("/settings/BitrateVideo2mp4", ui->spinBox_bitrate_vid_2mp4->value());
    configIniWrite->setValue("/settings/BitrateAudio2mp4", ui->spinBox_bitrate_audio_2mp4->value());
    configIniWrite->setValue("/settings/vcodecCopy", ui->checkBox_vcodec_copy_2mp4->isChecked());
    configIniWrite->setValue("/settings/acodecCopy", ui->checkBox_acodec_copy_2mp4->isChecked());
    configIniWrite->setValue("/settings/ExtraCommand2mp4", ui->lineEdit_ExCommand_2mp4->text());
    //==================== 存储输出路径设置 ========================
    configIniWrite->setValue("/settings/OutPutPath", ui->lineEdit_outputPath->text());
    configIniWrite->setValue("/settings/OutPutPathIsEnabled", ui->checkBox_OutPath_isEnabled->isChecked());
    configIniWrite->setValue("/settings/checkBox_OutPath_KeepOriginalFileName", ui->checkBox_OutPath_KeepOriginalFileName->isChecked());
    configIniWrite->setValue("/settings/checkBox_OutPath_Overwrite", ui->checkBox_OutPath_Overwrite->isChecked());
    //=================== 存储Anime4k设置 =============================
    configIniWrite->setValue("/settings/checkBox_HDNMode_Anime4k", ui->checkBox_HDNMode_Anime4k->isChecked());
    configIniWrite->setValue("/settings/checkBox_FastMode_Anime4K", ui->checkBox_FastMode_Anime4K->isChecked());
    configIniWrite->setValue("/settings/checkBox_ACNet_Anime4K", ui->checkBox_ACNet_Anime4K->isChecked());
    configIniWrite->setValue("/settings/checkBox_GPUMode_Anime4K", ui->checkBox_GPUMode_Anime4K->isChecked());
    configIniWrite->setValue("/settings/spinBox_Passes_Anime4K", ui->spinBox_Passes_Anime4K->value());
    configIniWrite->setValue("/settings/spinBox_PushColorCount_Anime4K", ui->spinBox_PushColorCount_Anime4K->value());
    configIniWrite->setValue("/settings/doubleSpinBox_PushColorStrength_Anime4K", ui->doubleSpinBox_PushColorStrength_Anime4K->value());
    configIniWrite->setValue("/settings/doubleSpinBox_PushGradientStrength_Anime4K", ui->doubleSpinBox_PushGradientStrength_Anime4K->value());
    configIniWrite->setValue("/settings/checkBox_SpecifyGPU_Anime4k", ui->checkBox_SpecifyGPU_Anime4k->isChecked());
    configIniWrite->setValue("/settings/spinBox_PlatformID_Anime4k", ui->spinBox_PlatformID_Anime4k->value());
    configIniWrite->setValue("/settings/spinBox_DeviceID_Anime4k", ui->spinBox_DeviceID_Anime4k->value());
    //Pre-Processing
    configIniWrite->setValue("/settings/checkBox_EnablePreProcessing_Anime4k", ui->checkBox_EnablePreProcessing_Anime4k->isChecked());
    configIniWrite->setValue("/settings/checkBox_MedianBlur_Pre_Anime4k", ui->checkBox_MedianBlur_Pre_Anime4k->isChecked());
    configIniWrite->setValue("/settings/checkBox_MeanBlur_Pre_Anime4k", ui->checkBox_MeanBlur_Pre_Anime4k->isChecked());
    configIniWrite->setValue("/settings/checkBox_CASSharping_Pre_Anime4k", ui->checkBox_CASSharping_Pre_Anime4k->isChecked());
    configIniWrite->setValue("/settings/checkBox_GaussianBlurWeak_Pre_Anime4k", ui->checkBox_GaussianBlurWeak_Pre_Anime4k->isChecked());
    configIniWrite->setValue("/settings/checkBox_GaussianBlur_Pre_Anime4k", ui->checkBox_GaussianBlur_Pre_Anime4k->isChecked());
    configIniWrite->setValue("/settings/checkBox_BilateralFilter_Pre_Anime4k", ui->checkBox_BilateralFilter_Pre_Anime4k->isChecked());
    configIniWrite->setValue("/settings/checkBox_BilateralFilterFaster_Pre_Anime4k", ui->checkBox_BilateralFilterFaster_Pre_Anime4k->isChecked());
    //Post-Processing
    configIniWrite->setValue("/settings/checkBox_EnablePostProcessing_Anime4k", ui->checkBox_EnablePostProcessing_Anime4k->isChecked());
    configIniWrite->setValue("/settings/checkBox_MedianBlur_Post_Anime4k", ui->checkBox_MedianBlur_Post_Anime4k->isChecked());
    configIniWrite->setValue("/settings/checkBox_MeanBlur_Post_Anime4k", ui->checkBox_MeanBlur_Post_Anime4k->isChecked());
    configIniWrite->setValue("/settings/checkBox_CASSharping_Post_Anime4k", ui->checkBox_CASSharping_Post_Anime4k->isChecked());
    configIniWrite->setValue("/settings/checkBox_GaussianBlurWeak_Post_Anime4k", ui->checkBox_GaussianBlurWeak_Post_Anime4k->isChecked());
    configIniWrite->setValue("/settings/checkBox_GaussianBlur_Post_Anime4k", ui->checkBox_GaussianBlur_Post_Anime4k->isChecked());
    configIniWrite->setValue("/settings/checkBox_BilateralFilter_Post_Anime4k", ui->checkBox_BilateralFilter_Post_Anime4k->isChecked());
    configIniWrite->setValue("/settings/checkBox_BilateralFilterFaster_Post_Anime4k", ui->checkBox_BilateralFilterFaster_Post_Anime4k->isChecked());
    //========================= 存储兼容性测试结果 ================
    configIniWrite->setValue("/settings/checkBox_isCompatible_Waifu2x_NCNN_Vulkan_NEW", ui->checkBox_isCompatible_Waifu2x_NCNN_Vulkan_NEW->isChecked());
    configIniWrite->setValue("/settings/checkBox_isCompatible_Waifu2x_NCNN_Vulkan_NEW_FP16P", ui->checkBox_isCompatible_Waifu2x_NCNN_Vulkan_NEW_FP16P->isChecked());
    configIniWrite->setValue("/settings/checkBox_isCompatible_Waifu2x_NCNN_Vulkan_OLD", ui->checkBox_isCompatible_Waifu2x_NCNN_Vulkan_OLD->isChecked());
    configIniWrite->setValue("/settings/checkBox_isCompatible_Waifu2x_Converter", ui->checkBox_isCompatible_Waifu2x_Converter->isChecked());
    configIniWrite->setValue("/settings/checkBox_isCompatible_SRMD_NCNN_Vulkan", ui->checkBox_isCompatible_SRMD_NCNN_Vulkan->isChecked());
    configIniWrite->setValue("/settings/checkBox_isCompatible_Anime4k_CPU", ui->checkBox_isCompatible_Anime4k_CPU->isChecked());
    configIniWrite->setValue("/settings/checkBox_isCompatible_Anime4k_GPU", ui->checkBox_isCompatible_Anime4k_GPU->isChecked());
    configIniWrite->setValue("/settings/checkBox_isCompatible_PythonExtension", ui->checkBox_isCompatible_PythonExtension->isChecked());
    configIniWrite->setValue("/settings/checkBox_isCompatible_FFmpeg", ui->checkBox_isCompatible_FFmpeg->isChecked());
    configIniWrite->setValue("/settings/checkBox_isCompatible_FFprobe", ui->checkBox_isCompatible_FFprobe->isChecked());
    configIniWrite->setValue("/settings/checkBox_isCompatible_ImageMagick", ui->checkBox_isCompatible_ImageMagick->isChecked());
    configIniWrite->setValue("/settings/checkBox_isCompatible_Gifsicle", ui->checkBox_isCompatible_Gifsicle->isChecked());
    configIniWrite->setValue("/settings/checkBox_isCompatible_SoX", ui->checkBox_isCompatible_SoX->isChecked());
    configIniWrite->setValue("/settings/checkBox_isCompatible_Waifu2x_Caffe_CPU", ui->checkBox_isCompatible_Waifu2x_Caffe_CPU->isChecked());
    configIniWrite->setValue("/settings/checkBox_isCompatible_Waifu2x_Caffe_GPU", ui->checkBox_isCompatible_Waifu2x_Caffe_GPU->isChecked());
    configIniWrite->setValue("/settings/checkBox_isCompatible_Waifu2x_Caffe_cuDNN", ui->checkBox_isCompatible_Waifu2x_Caffe_cuDNN->isChecked());
    configIniWrite->setValue("/settings/checkBox_isCompatible_Realsr_NCNN_Vulkan", ui->checkBox_isCompatible_Realsr_NCNN_Vulkan->isChecked());
    //========
    return 0;
}
/*
读取&应用设置
如果设置文件不存在则生成默认设置文件,读取设置,应用设置
*/
int MainWindow::Settings_Read_Apply()
{
    QString settings_ini = Current_Path+"/settings.ini";
    if(!file_isFileExist(settings_ini))
    {
        Settings_Save();
        Settings_Read_Apply();
        return 0;
    }
    else
    {
        QSettings *configIniRead_ver = new QSettings(settings_ini, QSettings::IniFormat);
        configIniRead_ver->setIniCodec(QTextCodec::codecForName("UTF-8"));
        QString Settings_VERSION = configIniRead_ver->value("/settings/VERSION").toString();
        if(Settings_VERSION!=VERSION)
        {
            Settings_Save();
            Settings_Read_Apply();
            return 0;
        }
    }
    //=================
    QSettings *configIniRead = new QSettings(settings_ini, QSettings::IniFormat);
    configIniRead->setIniCodec(QTextCodec::codecForName("UTF-8"));
    //=================== 加载全局字体设置 =========================
    ui->spinBox_GlobalFontSize->setValue(configIniRead->value("/settings/GlobalFontSize").toInt());
    ui->fontComboBox_CustFont->setCurrentFont(configIniRead->value("/settings/CustFont").value<QFont>());
    ui->checkBox_isCustFontEnable->setChecked(configIniRead->value("/settings/CustFont_isEnabled").toBool());
    Set_Font_fixed();
    //=======  加载放大值和降噪值  ======
    ui->spinBox_ScaleRatio_image->setValue(configIniRead->value("/settings/ImageScaleRatio").toInt());
    ui->spinBox_ScaleRatio_gif->setValue(configIniRead->value("/settings/GIFScaleRatio").toInt());
    ui->spinBox_ScaleRatio_video->setValue(configIniRead->value("/settings/VideoScaleRatio").toInt());
    //============= 加载自定义宽度和高度 ============================
    ui->spinBox_CustRes_width->setValue(configIniRead->value("/settings/CustResWidth").toInt());
    ui->spinBox_CustRes_height->setValue(configIniRead->value("/settings/CustResHeight").toInt());
    ui->comboBox_AspectRatio_custRes->setCurrentIndex(configIniRead->value("/settings/CustResAspectRatioMode").toInt());
    //============ 加载 线程数量 ==================================
    ui->spinBox_ThreadNum_image->setValue(configIniRead->value("/settings/ImageThreadNum").toInt());
    ui->spinBox_ThreadNum_gif_internal->setValue(configIniRead->value("/settings/GIFThreadNumInternal").toInt());
    ui->spinBox_ThreadNum_video_internal->setValue(configIniRead->value("/settings/VideoThreadNumInternal").toInt());
    //================ 加载 引擎设置 ================================
    isShowAnime4kWarning=false;
    ui->comboBox_Engine_Image->setCurrentIndex(configIniRead->value("/settings/ImageEngine").toInt());
    ui->comboBox_Engine_GIF->setCurrentIndex(configIniRead->value("/settings/GIFEngine").toInt());
    ui->comboBox_Engine_Video->setCurrentIndex(configIniRead->value("/settings/VideoEngine").toInt());
    ui->comboBox_ImageStyle->setCurrentIndex(configIniRead->value("/settings/ImageStyle").toInt());
    ui->comboBox_model_vulkan->setCurrentIndex(configIniRead->value("/settings/ModelVulkan").toInt());
    ui->spinBox_TileSize->setValue(configIniRead->value("/settings/TileSize").toInt());
    ui->spinBox_BlockSize_converter->setValue(configIniRead->value("/settings/BlockSizeConverter").toInt());
    ui->checkBox_DisableGPU_converter->setChecked(configIniRead->value("/settings/DisableGPUConverter").toBool());
    ui->checkBox_ForceOpenCL_converter->setChecked(configIniRead->value("/settings/ForceOpenCLConverter").toBool());
    ui->checkBox_TTA_vulkan->setChecked(configIniRead->value("/settings/TTAVulkan").toBool());
    ui->checkBox_TTA_converter->setChecked(configIniRead->value("/settings/TTAConverter").toBool());
    ui->checkBox_TTA_srmd->setChecked(configIniRead->value("/settings/TTA_SRMD").toBool());
    ui->spinBox_TileSize_srmd->setValue(configIniRead->value("/settings/TileSize_SRMD").toInt());
    ui->comboBox_version_Waifu2xNCNNVulkan->setCurrentIndex(configIniRead->value("/settings/Version_Waifu2xNCNNVulkan").toInt());
    //===
    ui->checkBox_TTA_RealsrNCNNVulkan->setChecked(configIniRead->value("/settings/checkBox_TTA_RealsrNCNNVulkan").toBool());
    ui->comboBox_Model_RealsrNCNNVulkan->setCurrentIndex(configIniRead->value("/settings/comboBox_Model_RealsrNCNNVulkan").toInt());
    ui->spinBox_TileSize_RealsrNCNNVulkan->setValue(configIniRead->value("/settings/spinBox_TileSize_RealsrNCNNVulkan").toInt());
    //===
    ui->checkBox_TTA_Waifu2xCaffe->setChecked(configIniRead->value("/settings/TTA_Waifu2xCaffe").toBool());
    ui->comboBox_Model_2D_Waifu2xCaffe->setCurrentIndex(configIniRead->value("/settings/Model_2D_Waifu2xCaffe").toInt());
    ui->comboBox_Model_3D_Waifu2xCaffe->setCurrentIndex(configIniRead->value("/settings/Model_3D_Waifu2xCaffe").toInt());
    ui->comboBox_ProcessMode_Waifu2xCaffe->setCurrentIndex(configIniRead->value("/settings/ProcessMode_Waifu2xCaffe").toInt());
    ui->spinBox_BatchSize_Waifu2xCaffe->setValue(configIniRead->value("/settings/BatchSize_Waifu2xCaffe").toInt());
    ui->spinBox_GPUID_Waifu2xCaffe->setValue(configIniRead->value("/settings/GPUID_Waifu2xCaffe").toInt());
    ui->spinBox_SplitSize_Waifu2xCaffe->setValue(configIniRead->value("/settings/SplitSize_Waifu2xCaffe").toInt());
    //GPU ID List
    //Waifu2x-NCNN-Vulkan
    Available_GPUID = configIniRead->value("/settings/Available_GPUID_Waifu2xNCNNVulkan").toStringList();
    Waifu2x_DetectGPU_finished();
    ui->comboBox_GPUID->setCurrentIndex(configIniRead->value("/settings/CurrentGPUID_Waifu2xNCNNVulkan").toInt());
    on_comboBox_GPUID_currentIndexChanged(0);
    //Realsr_ncnn_vulkan
    Available_GPUID_Realsr_ncnn_vulkan = configIniRead->value("/settings/Available_GPUID_Realsr_ncnn_vulkan").toStringList();
    Realsr_ncnn_vulkan_DetectGPU_finished();
    ui->comboBox_GPUID_RealsrNCNNVulkan->setCurrentIndex(configIniRead->value("/settings/comboBox_GPUID_RealsrNCNNVulkan").toInt());
    //Waifu2x-Converter
    Available_ProcessorList_converter = configIniRead->value("/settings/Available_ProcessorList_converter").toStringList();
    Waifu2x_DumpProcessorList_converter_finished();
    ui->comboBox_TargetProcessor_converter->setCurrentIndex(configIniRead->value("/settings/comboBox_TargetProcessor_converter").toInt());
    on_comboBox_TargetProcessor_converter_currentIndexChanged(0);
    //SRMD-NCNN-Vulkan
    Available_GPUID_srmd = configIniRead->value("/settings/Available_GPUID_srmd").toStringList();
    SRMD_DetectGPU_finished();
    ui->comboBox_GPUID_srmd->setCurrentIndex(configIniRead->value("/settings/comboBox_GPUID_srmd").toInt());
    on_comboBox_GPUID_srmd_currentIndexChanged(0);
    //================= 加载 扩展名 ===========================
    ui->Ext_image->setText(configIniRead->value("/settings/ImageEXT").toString());
    ui->Ext_video->setText(configIniRead->value("/settings/VideoEXT").toString());
    //================== 加载 杂项设置 ==================================
    ui->checkBox_custres_isAll->setChecked(configIniRead->value("/settings/checkBox_custres_isAll").toBool());
    ui->checkBox_SaveAsJPG->setChecked(configIniRead->value("/settings/SaveAsJPG").toBool());
    ui->checkBox_CompressJPG->setChecked(configIniRead->value("/settings/CompressJPG").toBool());
    ui->checkBox_DelOriginal->setChecked(configIniRead->value("/settings/DelOriginal").toBool());
    ui->checkBox_Move2RecycleBin->setChecked(configIniRead->value("/settings/Move2RecycleBin").toBool());
    ui->checkBox_OptGIF->setChecked(configIniRead->value("/settings/OptGIF").toBool());
    ui->checkBox_NfSound->setChecked(configIniRead->value("/settings/NFSound").toBool());
    ui->checkBox_ReProcFinFiles->setChecked(configIniRead->value("/settings/ReProFinFiles").toBool());
    ui->checkBox_ShowInterPro->setChecked(configIniRead->value("/settings/ShowInterPro").toBool());
    ui->checkBox_UpdatePopup->setChecked(configIniRead->value("/settings/UpdatePopup").toBool());
    ui->checkBox_FileListAutoSlide->setChecked(configIniRead->value("/settings/FileListAutoScroll").toBool());
    ui->checkBox_AutoSaveSettings->setChecked(configIniRead->value("/settings/AutoSaveSettings").toBool());
    ui->checkBox_AlwaysHideSettings->setChecked(configIniRead->value("/settings/AlwaysHideSettings").toBool());
    ui->checkBox_AlwaysHideTextBrowser->setChecked(configIniRead->value("/settings/AlwaysHideTextBrowser").toBool());
    ui->spinBox_JPGCompressedQuality->setValue(configIniRead->value("/settings/JPGCompressedQuality").toInt());
    ui->checkBox_ScanSubFolders->setChecked(configIniRead->value("/settings/ScanSubFolders").toBool());
    ui->checkBox_FileList_Interactive->setChecked(configIniRead->value("/settings/InteractiveFileList").toBool());
    ui->spinBox_retry->setValue(configIniRead->value("/settings/RetryTimes").toInt());
    ui->checkBox_AutoDetectAlphaChannel->setChecked(configIniRead->value("/settings/AutoDetectAlphaChannel").toBool());
    ui->checkBox_PromptWhenExit->setChecked(configIniRead->value("/settings/PromptWhenExit").toBool());
    ui->checkBox_KeepVideoCache->setChecked(configIniRead->value("/settings/KeepVideoCache").toBool());
    //===
    ui->checkBox_ProcessVideoBySegment->setChecked(configIniRead->value("/settings/ProcessVideoBySegment").toBool());
    ui->spinBox_SegmentDuration->setValue(configIniRead->value("/settings/SegmentDuration").toInt());
    //=========
    ui->checkBox_AudioDenoise->setChecked(configIniRead->value("/settings/AudioDenoise").toBool());
    ui->doubleSpinBox_AudioDenoiseLevel->setValue(configIniRead->value("/settings/AudioDenoiseLevel").toDouble());
    //=========
    ui->checkBox_PreProcessImage->setChecked(configIniRead->value("/settings/checkBox_PreProcessImage").toBool());
    //=================== 加载 textbrowser 设置 ==========================
    ui->spinBox_textbrowser_fontsize->setValue(configIniRead->value("/settings/TextBrowserFontSize").toInt());
    //=================== 加载视频设置 ===========================
    ui->checkBox_videoSettings_isEnabled->setChecked(configIniRead->value("/settings/VideoSettingsIsEnabled").toBool());
    //===
    ui->lineEdit_encoder_vid->setText(configIniRead->value("/settings/EncoderVideo").toString());
    ui->lineEdit_encoder_audio->setText(configIniRead->value("/settings/EncoderAudio").toString());
    ui->lineEdit_pixformat->setText(configIniRead->value("/settings/PixelFormat").toString());
    ui->spinBox_bitrate_vid->setValue(configIniRead->value("/settings/BitrateVideo").toInt());
    ui->spinBox_bitrate_audio->setValue(configIniRead->value("/settings/BitrateAudio").toInt());
    ui->lineEdit_ExCommand_output->setText(configIniRead->value("/settings/ExtraCommandOutput").toString());
    //===
    ui->spinBox_bitrate_vid_2mp4->setValue(configIniRead->value("/settings/BitrateVideo2mp4").toInt());
    ui->spinBox_bitrate_audio_2mp4->setValue(configIniRead->value("/settings/BitrateAudio2mp4").toInt());
    ui->checkBox_vcodec_copy_2mp4->setChecked(configIniRead->value("/settings/vcodecCopy").toBool());
    ui->checkBox_acodec_copy_2mp4->setChecked(configIniRead->value("/settings/acodecCopy").toBool());
    ui->lineEdit_ExCommand_2mp4->setText(configIniRead->value("/settings/ExtraCommand2mp4").toString());
    //=============== 加载输出路径设置 ===========================
    ui->lineEdit_outputPath->setText(configIniRead->value("/settings/OutPutPath").toString());
    ui->checkBox_OutPath_isEnabled->setChecked(configIniRead->value("/settings/OutPutPathIsEnabled").toBool());
    ui->checkBox_OutPath_KeepOriginalFileName->setChecked(configIniRead->value("/settings/checkBox_OutPath_KeepOriginalFileName").toBool());
    ui->checkBox_OutPath_Overwrite->setChecked(configIniRead->value("/settings/checkBox_OutPath_Overwrite").toBool());
    //================== 加载Anime4k设置 ===================================
    ui->checkBox_HDNMode_Anime4k->setChecked(configIniRead->value("/settings/checkBox_HDNMode_Anime4k").toBool());
    ui->checkBox_FastMode_Anime4K->setChecked(configIniRead->value("/settings/checkBox_FastMode_Anime4K").toBool());
    ui->checkBox_ACNet_Anime4K->setChecked(configIniRead->value("/settings/checkBox_ACNet_Anime4K").toBool());
    ui->checkBox_GPUMode_Anime4K->setChecked(configIniRead->value("/settings/checkBox_GPUMode_Anime4K").toBool());
    ui->spinBox_Passes_Anime4K->setValue(configIniRead->value("/settings/spinBox_Passes_Anime4K").toInt());
    ui->spinBox_PushColorCount_Anime4K->setValue(configIniRead->value("/settings/spinBox_PushColorCount_Anime4K").toInt());
    ui->doubleSpinBox_PushColorStrength_Anime4K->setValue(configIniRead->value("/settings/doubleSpinBox_PushColorStrength_Anime4K").toDouble());
    ui->doubleSpinBox_PushGradientStrength_Anime4K->setValue(configIniRead->value("/settings/doubleSpinBox_PushGradientStrength_Anime4K").toDouble());
    ui->checkBox_SpecifyGPU_Anime4k->setChecked(configIniRead->value("/settings/checkBox_SpecifyGPU_Anime4k").toBool());
    ui->spinBox_PlatformID_Anime4k->setValue(configIniRead->value("/settings/spinBox_PlatformID_Anime4k").toInt());
    ui->spinBox_DeviceID_Anime4k->setValue(configIniRead->value("/settings/spinBox_DeviceID_Anime4k").toInt());
    //Pre-Processing
    ui->checkBox_EnablePreProcessing_Anime4k->setChecked(configIniRead->value("/settings/checkBox_EnablePreProcessing_Anime4k").toBool());
    ui->checkBox_MedianBlur_Pre_Anime4k->setChecked(configIniRead->value("/settings/checkBox_MedianBlur_Pre_Anime4k").toBool());
    ui->checkBox_MeanBlur_Pre_Anime4k->setChecked(configIniRead->value("/settings/checkBox_MeanBlur_Pre_Anime4k").toBool());
    ui->checkBox_CASSharping_Pre_Anime4k->setChecked(configIniRead->value("/settings/checkBox_CASSharping_Pre_Anime4k").toBool());
    ui->checkBox_GaussianBlurWeak_Pre_Anime4k->setChecked(configIniRead->value("/settings/checkBox_GaussianBlurWeak_Pre_Anime4k").toBool());
    ui->checkBox_GaussianBlur_Pre_Anime4k->setChecked(configIniRead->value("/settings/checkBox_GaussianBlur_Pre_Anime4k").toBool());
    ui->checkBox_BilateralFilter_Pre_Anime4k->setChecked(configIniRead->value("/settings/checkBox_BilateralFilter_Pre_Anime4k").toBool());
    ui->checkBox_BilateralFilterFaster_Pre_Anime4k->setChecked(configIniRead->value("/settings/checkBox_BilateralFilterFaster_Pre_Anime4k").toBool());
    //Post-Processing
    ui->checkBox_EnablePostProcessing_Anime4k->setChecked(configIniRead->value("/settings/checkBox_EnablePostProcessing_Anime4k").toBool());
    ui->checkBox_MedianBlur_Post_Anime4k->setChecked(configIniRead->value("/settings/checkBox_MedianBlur_Post_Anime4k").toBool());
    ui->checkBox_MeanBlur_Post_Anime4k->setChecked(configIniRead->value("/settings/checkBox_MeanBlur_Post_Anime4k").toBool());
    ui->checkBox_CASSharping_Post_Anime4k->setChecked(configIniRead->value("/settings/checkBox_CASSharping_Post_Anime4k").toBool());
    ui->checkBox_GaussianBlurWeak_Post_Anime4k->setChecked(configIniRead->value("/settings/checkBox_GaussianBlurWeak_Post_Anime4k").toBool());
    ui->checkBox_GaussianBlur_Post_Anime4k->setChecked(configIniRead->value("/settings/checkBox_GaussianBlur_Post_Anime4k").toBool());
    ui->checkBox_BilateralFilter_Post_Anime4k->setChecked(configIniRead->value("/settings/checkBox_BilateralFilter_Post_Anime4k").toBool());
    ui->checkBox_BilateralFilterFaster_Post_Anime4k->setChecked(configIniRead->value("/settings/checkBox_BilateralFilterFaster_Post_Anime4k").toBool());
    //===================== 加载兼容性测试结果 ============================
    isCompatible_Waifu2x_NCNN_Vulkan_NEW = configIniRead->value("/settings/checkBox_isCompatible_Waifu2x_NCNN_Vulkan_NEW").toBool();
    isCompatible_Waifu2x_NCNN_Vulkan_NEW_FP16P = configIniRead->value("/settings/checkBox_isCompatible_Waifu2x_NCNN_Vulkan_NEW_FP16P").toBool();
    isCompatible_Waifu2x_NCNN_Vulkan_OLD = configIniRead->value("/settings/checkBox_isCompatible_Waifu2x_NCNN_Vulkan_OLD").toBool();
    isCompatible_Waifu2x_Converter = configIniRead->value("/settings/checkBox_isCompatible_Waifu2x_Converter").toBool();
    isCompatible_SRMD_NCNN_Vulkan = configIniRead->value("/settings/checkBox_isCompatible_SRMD_NCNN_Vulkan").toBool();
    isCompatible_Anime4k_CPU = configIniRead->value("/settings/checkBox_isCompatible_Anime4k_CPU").toBool();
    isCompatible_Anime4k_GPU = configIniRead->value("/settings/checkBox_isCompatible_Anime4k_GPU").toBool();
    isCompatible_PythonExtension = configIniRead->value("/settings/checkBox_isCompatible_PythonExtension").toBool();
    isCompatible_FFmpeg = configIniRead->value("/settings/checkBox_isCompatible_FFmpeg").toBool();
    isCompatible_FFprobe = configIniRead->value("/settings/checkBox_isCompatible_FFprobe").toBool();
    isCompatible_ImageMagick = configIniRead->value("/settings/checkBox_isCompatible_ImageMagick").toBool();
    isCompatible_Gifsicle = configIniRead->value("/settings/checkBox_isCompatible_Gifsicle").toBool();
    isCompatible_SoX = configIniRead->value("/settings/checkBox_isCompatible_SoX").toBool();
    isCompatible_Waifu2x_Caffe_CPU = configIniRead->value("/settings/checkBox_isCompatible_Waifu2x_Caffe_CPU").toBool();
    isCompatible_Waifu2x_Caffe_GPU = configIniRead->value("/settings/checkBox_isCompatible_Waifu2x_Caffe_GPU").toBool();
    isCompatible_Waifu2x_Caffe_cuDNN = configIniRead->value("/settings/checkBox_isCompatible_Waifu2x_Caffe_cuDNN").toBool();
    isCompatible_Realsr_NCNN_Vulkan = configIniRead->value("/settings/checkBox_isCompatible_Realsr_NCNN_Vulkan").toBool();
    //===
    ui->checkBox_isCompatible_Waifu2x_NCNN_Vulkan_NEW->setChecked(isCompatible_Waifu2x_NCNN_Vulkan_NEW);
    ui->checkBox_isCompatible_Waifu2x_NCNN_Vulkan_NEW_FP16P->setChecked(isCompatible_Waifu2x_NCNN_Vulkan_NEW_FP16P);
    ui->checkBox_isCompatible_Waifu2x_NCNN_Vulkan_OLD->setChecked(isCompatible_Waifu2x_NCNN_Vulkan_OLD);
    ui->checkBox_isCompatible_Waifu2x_Converter->setChecked(isCompatible_Waifu2x_Converter);
    ui->checkBox_isCompatible_SRMD_NCNN_Vulkan->setChecked(isCompatible_SRMD_NCNN_Vulkan);
    ui->checkBox_isCompatible_Anime4k_CPU->setChecked(isCompatible_Anime4k_CPU);
    ui->checkBox_isCompatible_Anime4k_GPU->setChecked(isCompatible_Anime4k_GPU);
    ui->checkBox_isCompatible_PythonExtension->setChecked(isCompatible_PythonExtension);
    ui->checkBox_isCompatible_FFmpeg->setChecked(isCompatible_FFmpeg);
    ui->checkBox_isCompatible_FFprobe->setChecked(isCompatible_FFprobe);
    ui->checkBox_isCompatible_ImageMagick->setChecked(isCompatible_ImageMagick);
    ui->checkBox_isCompatible_Gifsicle->setChecked(isCompatible_Gifsicle);
    ui->checkBox_isCompatible_SoX->setChecked(isCompatible_SoX);
    ui->checkBox_isCompatible_Waifu2x_Caffe_CPU->setChecked(isCompatible_Waifu2x_Caffe_CPU);
    ui->checkBox_isCompatible_Waifu2x_Caffe_GPU->setChecked(isCompatible_Waifu2x_Caffe_GPU);
    ui->checkBox_isCompatible_Waifu2x_Caffe_cuDNN->setChecked(isCompatible_Waifu2x_Caffe_cuDNN);
    ui->checkBox_isCompatible_Realsr_NCNN_Vulkan->setChecked(isCompatible_Realsr_NCNN_Vulkan);
    //==================== 加载语言设置 =====================
    ui->comboBox_language->setCurrentIndex(configIniRead->value("/settings/Language").toInt());
    on_comboBox_language_currentIndexChanged(0);
    //====================================================
    on_checkBox_SaveAsJPG_stateChanged(0);
    on_checkBox_AlwaysHideSettings_stateChanged(0);
    on_checkBox_AlwaysHideTextBrowser_stateChanged(0);
    on_checkBox_DelOriginal_stateChanged(0);
    on_checkBox_FileList_Interactive_stateChanged(0);
    on_checkBox_OutPath_isEnabled_stateChanged(0);
    on_checkBox_AudioDenoise_stateChanged(0);
    on_checkBox_ProcessVideoBySegment_stateChanged(0);
    on_checkBox_EnablePreProcessing_Anime4k_stateChanged(0);
    on_checkBox_EnablePostProcessing_Anime4k_stateChanged(0);
    on_checkBox_SpecifyGPU_Anime4k_stateChanged(0);
    on_checkBox_GPUMode_Anime4K_stateChanged(0);
    on_checkBox_ShowInterPro_stateChanged(0);
    //====
    on_comboBox_version_Waifu2xNCNNVulkan_currentIndexChanged(0);
    on_comboBox_Engine_GIF_currentIndexChanged(0);
    isShowAnime4kWarning=false;
    on_comboBox_Engine_Image_currentIndexChanged(0);
    on_comboBox_Engine_Video_currentIndexChanged(0);
    on_comboBox_ImageStyle_currentIndexChanged(0);
    on_comboBox_model_vulkan_currentIndexChanged(0);
    ui->spinBox_DenoiseLevel_image->setValue(configIniRead->value("/settings/ImageDenoiseLevel").toInt());
    ui->spinBox_DenoiseLevel_gif->setValue(configIniRead->value("/settings/GIFDenoiseLevel").toInt());
    ui->spinBox_DenoiseLevel_video->setValue(configIniRead->value("/settings/VideoDenoiseLevel").toInt());
    //=====
    on_spinBox_textbrowser_fontsize_valueChanged(0);
    //===
    on_comboBox_AspectRatio_custRes_currentIndexChanged(0);
    //=====
    Init_Table();
    //====
    on_checkBox_acodec_copy_2mp4_stateChanged(1);
    on_checkBox_vcodec_copy_2mp4_stateChanged(1);
    on_checkBox_videoSettings_isEnabled_stateChanged(1);
    //==================================
    return 0;
}
/*
保存设置pushbutton
保存设置,弹窗
*/
void MainWindow::on_pushButton_SaveSettings_clicked()
{
    Settings_Save();
    QMessageBox *MSG = new QMessageBox();
    MSG->setWindowTitle(tr("Notification"));
    MSG->setText(tr("Settings saved successfully!"));
    MSG->setIcon(QMessageBox::Information);
    MSG->setModal(false);
    MSG->show();
}
/*
重置设置
删除设置文件,重置标记=true,弹窗
*/
void MainWindow::on_pushButton_ResetSettings_clicked()
{
    QString settings_ini = Current_Path+"/settings.ini";
    QFile::remove(settings_ini);
    Settings_isReseted = true;
    QMessageBox *MSG = new QMessageBox();
    MSG->setWindowTitle(tr("Notification"));
    MSG->setText(tr("The settings file has been reset, please restart the software manually for the default settings to take effect."));
    MSG->setIcon(QMessageBox::Information);
    MSG->setModal(false);
    MSG->show();
}

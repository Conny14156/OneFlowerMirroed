﻿using System;
using System.Collections.Generic;

namespace EditorResources.Functionality
{
    public static class EditorEvents
    {
        #region ModLoadSave
        public static EventHandler<NewModCreateEventArgs> onModCreate;
        public static EventHandler<ModFileSelectedEventArgs> onModSelected;
        public static EventHandler<ModLoadEventArgs> onModLoad;
        public static EventHandler<ModFinishedLoadedEventArgs> onModFinishedLoading;

        public static EventHandler<EngineOnModSelectedLoadedEventArgs> engineOnModSelectedLoaded;

        public static EventHandler<ModSaveEventArgs> onModSave;

        public static void OnModSave(ModSaveEventArgs args)
        {
            onModSave?.Invoke(null, args);
        }

        public static void OnModCreate(NewModCreateEventArgs args)
        {
            onModCreate?.Invoke(null, args);
        }

        public static void OnModSelected(ModFileSelectedEventArgs args)
        {
            onModSelected?.Invoke(null, args);
        }

        public static void OnModLoad(ModLoadEventArgs args)
        {
            onModLoad?.Invoke(null, args);
        }

        public static void OnModFinishedLoading(ModFinishedLoadedEventArgs args)
        {
            onModFinishedLoading?.Invoke(null, args);
        }

        public static void EngineOnModSelectedLoaded(EngineOnModSelectedLoadedEventArgs args)
        {
            engineOnModSelectedLoaded?.Invoke(null, args);
        }

        #endregion

        #region log
        public static EventHandler<EditorLogEventArgs> onLogEvent;

        public static void OnLogEvent(EditorLogEventArgs args)
        {
            onLogEvent?.Invoke(null, args);
        }
        #endregion


        #region ZoneView

        public static EventHandler<EditorZoneSelectedEventArgs> onZoneSelectedEvent;

        public static void OnZoneSelectedEvent(EditorZoneSelectedEventArgs args)
        {
            onZoneSelectedEvent?.Invoke(null, args);
        }

        public static EventHandler<EditorZoneSelectedFinishedLoadingEventArgs> onZoneSelectedFinishedLoadingEvent;

        public static void OnZoneSelectedFinishedLoadingEvent(EditorZoneSelectedFinishedLoadingEventArgs args)
        {
            onZoneSelectedFinishedLoadingEvent?.Invoke(null, args);
        }

        #endregion

        #region ObjectTreeView

        public static EventHandler<OnObjectLoadEventArgs> onObjectLoadEvent;

        public static void OnObjectLoadEvent(OnObjectLoadEventArgs args)
        {
            onObjectLoadEvent?.Invoke(null, args);
        }

        #endregion

        #region TextureMap

        public static EventHandler<OnTextureMapLoadedFromFileEventArgs> onTextureMapLoadedFromFile;

        public static void OnTextureMapLoadedFromFileEvent(OnTextureMapLoadedFromFileEventArgs args)
        {
            onTextureMapLoadedFromFile?.Invoke(null, args);
        }

        #endregion

    }

    #region EventArgs

    public class EditorZoneSelectedFinishedLoadingEventArgs : EventArgs
    {
        public List<Tuple<string, uint, string, uint, string>> objectsLoaded = new List<Tuple<string, uint, string, uint, string>>();
    }

    public class EditorZoneSelectedEventArgs : EventArgs
    {
        public string ModOrigin;
        public string ZoneName;
        public UInt32 ZoneID;
    }

    public class EngineOnModSelectedLoadedEventArgs : EventArgs
    {
        public ModWindow.ModDependencyList Dependencies;
    }

    public class ModFileSelectedEventArgs : EventArgs
    {
        public String fileName;
    }

    public class EditorLogEventArgs : EventArgs
    {
        public Message.Message logMessage;
    }

    public class ModLoadEventArgs : EventArgs
    {
        public String modName;
    }

    public class NewModCreateEventArgs : EventArgs
    {
        public String modName;
        public List<String> dependencies;
        public bool? createMaster;
    }

    public class ModSaveEventArgs : EventArgs
    {
        /**Empty**/
    }

    public class ModFinishedLoadedEventArgs : EventArgs
    {
        public List<Tuple<String, UInt32, String>> zoneFiles = new List<Tuple<string, uint, string>>();
    }

    public class OnObjectLoadEventArgs : EventArgs
    {
        public string ModOrigin { get; set; }
        public string ObjectType { get; set; }
    }

    public class OnTextureMapLoadedFromFileEventArgs : EventArgs
    {
        public class Point
        {
            public int X { get; set; } = 0;
            public int Y { get; set; } = 0;
            public int H { get; set; } = 0;
            public int W { get; set; } = 0;
            public bool Rotated { get; set; } = false;
            public short R { get; set; } = 255;
            public short G { get; set; } = 255;
            public short B { get; set; } = 255;
        }
        public Dictionary<string, Point> MapPoints { get; set; }
    }

    #endregion
}

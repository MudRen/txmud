// tulu2.c ����· 

inherit ROOM;
void create()
{
        set("short", "����·");
        set("long", @LONG
��̫ƽ̹�Ļ���·����ȥ�о����Ǻܺã���ʱ����������ʿ
���������߷ɳ۶�������ƬƬ�ҳ����㲻�ɵüӿ��˽Ų����
���������·��
LONG
        );
       set("exits", ([
        "north" : "/d/path2/ch_k23",
                "south"             : __DIR__"tulu3",
                     ]) );
       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}

// tulu3.c ����· 

inherit ROOM;
void create()
{
        set("short", "����·");
        set("long", @LONG
��̫ƽ̹�Ļ���·����ȥ�о����Ǻܺã���ʱ����������ʿ
���������߷ɳ۶�������ƬƬ�ҳ����㲻�ɵüӿ��˽Ų����
���������·,���������Ͼ��ǻƺӿڱߵ��봨���ˡ�
LONG
        );
       set("exits", ([
                "north"             : __DIR__"tulu2",
                "south"             : __DIR__"zhenkou",
                     ]) );
       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}

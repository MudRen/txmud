// dt_fenduo.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������տյ����ģ�ֻ�м����ɲ�ɢ���ڵ��ϣ�����һ��ù
ζ���������ӵ�ǽ���϶�����һ��ң�ͨ�����ݵĵ�ľ��Ҳ����
�ò������ӣ��ƺ���΢��һ�¶�����ѡ�
LONG
);

        set("no_clean_up", 0);
        set("no_sleep_room", 0);
        set("exits", ([
                "north" : __DIR__"dt_fenduo_2",
                "west" : __DIR__"dt_fenduo_1",
                "south" : "/d/datong/pojiudayuan",
                "east" : __DIR__"dt_fenduo_3",
        ]));

        set("objects",([
        ]));

        setup();
        replace_program(ROOM);
}

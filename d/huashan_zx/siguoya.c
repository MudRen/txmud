// Room: siguoya.c by pian

inherit ROOM;

void create()
{
        set("short", "˼����");
        set("long", @LONG
˼�����ǻ�ɽ�ɵ��ӷ������صĹ����ͻᷣ��������ھ�
˼�ѹ�����������һ��СС��ɽ�����ǹ�˼����������ڱܷ�
���õġ�
�����Ӷ��治ʱ�������紵����
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 3 */
		"enter" : __DIR__"sg_dong",
		"southdown" : __DIR__"guange5",
		"east" : __DIR__"siguoya2",
]));
        set("outdoors", "huashan_p");
        setup();
        replace_program(ROOM);
}

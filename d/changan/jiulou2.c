// Room: /d/changan/jiulou2.c

inherit ROOM;

void create()
{
        set("short", "����¥����");
        set("long", @LONG
����������¥�Ķ�¥����������¥�������������ھ�������
�Ĵ�ٹ������롢С�ö�Ҫ��������������������ľ�����̩
·��¥����һƬ���ｻ���ϰ����Ĵ��к��ſ��ˡ�
LONG
        );

        set("night_long",@LONG
����������¥�Ķ�¥�������Ѿ������ˡ��Ĵ���ʰ�øɸɾ�
�����ϰ����������ߴ��
LONG
);
        set("no_clean_up", 0);
        set("no_sleep_room",1);
        set("exits", ([ /* sizeof() == 1 */
	"down" : __DIR__"jiulou",
	"up" : __DIR__"jiulou3",
]));
        set("objects",([
        __DIR__"npc/zuixiange_boss" : 1,
//	"/obj/gift/men" : 1,
]));
        set("NORIDE","С��¥��̫խ������������������ϲ�ȥ��");
        setup();
        replace_program(ROOM);
}

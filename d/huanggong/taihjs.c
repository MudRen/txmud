// Room: /d/huanggong/taihjs.c

inherit ROOM;

void create()
{
        set("short", "̫����ɽ");
        set("long", @LONG
������ȥ����ɽ�������ˣ���ˮ�����޲�����ʫ�续������
�����ﱻ����������Ʒ���š�ÿһ������ʾ�Ž����ߵĶ��߽�
�����ɶ��칤����ɽ����ˮ����ӳ��Ȥ��ż���м�ֻˮ������ˮ
��ɹ����㲻������ǰ�ľ�ɫ��ס�ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"yuhy",
  "up" : __DIR__"yujt",
]));
        set("no_clean_up", 0);

	set("outdoors", "huanggong");
        setup();
        replace_program(ROOM);
}


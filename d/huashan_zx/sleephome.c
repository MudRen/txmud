// Room: sleeroom.c

inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
�����ǻ�ɽ�ɵ��ӵ���Ϣ�ҡ����п�ǽ����һ��ͨ�̣�����
��ɨ�ĺܸɾ���������һ����Ⱦ�ġ����ܵĴ����������ţ�����
�ܰ����������ϣ���ܿ���������硣
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"guodaoe2",
]));
	set("sleep_room", 1);
	set(SAFE_ENV,1);

	setup();
}

// Room: /d/shaolin/gulou1.c

inherit ROOM;

void create()
{
	set("short", "��¥һ��");
	set("long", @LONG
�����ǹ�¥��һ�㣬������ֻ��������ǿ��ʱ���Ż��ù�ʾ
��������˵�������µ������ǲ������ġ���¥��Ȼ�Ѿ��ܹž��ˣ�
ǽ���ϵķ��Ѿ������˲��٣�¶�����������ש������������
��������С¥�������Ƕ��㡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"6zumiao",
  "up" : __DIR__"gulou2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

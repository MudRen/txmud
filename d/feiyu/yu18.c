// Room: /u/w/wangs/a/yu18.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������ĳ��������ܲ����ò͵�ʱ��ɣ����Գ�
����һ���˶�û�У��������Ӷ��ˣ���ֻ���Լ���Щ�Ե�
��伢�ˡ���ǽ����һ�ڴ�ˮ�ף���Ҫ�ǿ��˿�������Ҩ
(drink)ˮ�ȡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yu8",
  "east" : __DIR__"yu17",
]));
        set("objects", ([ /* sizeof() == 4 */
  __DIR__"obj/jitui" : 10,
  __DIR__"obj/jibozi" : 10,
  __DIR__"obj/jichi" : 10,
]));

	setup();
}

void init()
{
	add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	object me = this_player();

	if( (int)me->query("water") >= (int)me->max_water_capacity() )
		return notify_fail("���Ѿ���Ҳ�Ȳ���һ��ˮ�ˡ�\n");

	message_vision("$N��ˮ�ױ��ñ���Ҩ��ˮ���˼��ڡ�\n", me);
	me->add("water", 20);
	return 1;
}

// Room: /wiz/louth/a/xlu5.c

inherit ROOM;

void create()
{
	set("short", "С·��ͷ");
	set("long", @LONG
����һ�����۵��ּ�С·��·���Ǹߴ�İ���������������
��Ũ�ܵ���Ҷ��͸����£�һ��΢�紵������Ҷɳɳ���졣·��
���ǿ�һ�˶�ߵĴ�ʯͷ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xlu4",
]));

	set("item_desc",([
	"��ʯͷ" : "һ��޴����ʯ(rock)��\n",
]));

        set("outdoors","feiyu");
	setup();
}

void init()
{
        add_action("do_push","push");
}

int do_push(string arg)
{
	object me = this_player();

	if(arg != "��ʯ" && arg != "rock")
		return notify_fail("��Ҫ��ʲô��\n");

	if(query("exits/enter"))
		return notify_fail("��ʯ�Ѿ����ƿ��ˡ�\n");

	if( (me->query("force_factor") < 80) || (me->query("force") < 80) )
                return notify_fail("����������һ����ʯ�������ʯ��˿û����\n");

        message_vision("$N�������������һ�����ƿ�����ʯ��
ԭ����һ���ܵ�����ڡ�\n",me);

	me->add("force",-40);
	set("exits/enter",__DIR__"shidao1");
	call_out("greeting",5);
	return 1;
}

void greeting()
{
	if(query("exits/enter"))
	{
		write ("��ʯ�������˻�ȥ��\n");
		delete("exits/enter");
	}
}

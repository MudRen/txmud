// Room: /u/w/wangs/a/yu56.c

inherit ROOM;

void create()
{
	set("short", "��¥����");
	set("long", @LONG
������÷�ָ��¥��͸�����������С������������÷
��Բ�����۵ף��侰����ʤ�ա��ڸ�¥��һ�ǣ���һ�ȴ���
��(ping feng)��ס��������ߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"geloue",
  "down" : __DIR__"yu55",
]));

	set("item_desc",([
	"����" : "һ��ߴ�����磬�ϱ߻���һ��ɽˮ������Լ�����ܿ�����������и���Ӱ��\n",
	"ping feng" : "һ��ߴ�����磬�ϱ߻���һ��ɽˮ������Լ�����ܿ�����������и���Ӱ����\n",
]));

	setup();
}

void init()
{
        add_action("do_yao","yao");
}

int do_yao(string arg)
{
	object me = this_player(),ob;

	if( (arg != "��ɱ��") && (arg != "kill plate") )
		return notify_fail("����Ҫʲô��\n");

	if(me->query("class") != "rain")
		return 0;

	if(me->query_temp("louth_killer"))
		return notify_fail("�������˵����Ѿ�������һö�����ˡ�\n");

	message_vision("��������վ�������������õģ���Ȼ$N��ﱾ��ɱ����ң�
��������͸���һ�λ��ᣬ������ö����ȥ���������ɡ�\n",me);

	me->set_temp("louth_killer",1);
	ob=new(__DIR__"obj/lingpai");
	ob->move(me);
	return 1;
}

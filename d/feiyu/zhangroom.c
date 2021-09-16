// Room: /wiz/louth/a/zhangroom.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�����ң�������ʰ�þ�ϸ�쳣��һ��ȥ���ͷ�
��һ�����������ǽ�ǡ��������İ�Ӱ�У��ƺ���һŮ��
�ڵ�ͷ��˼��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yu103",
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

	if(arg != "�����" && arg != "rain plate")
		return notify_fail("����Ҫʲô��\n");

	if(sizeof(filter_array(children(__DIR__"obj/lingpai2"),(: clonep :))) > 0)
		return notify_fail("�������˵�����������Ѿ������ˣ���������һ����\n");

	message_vision ("��������վ�������������õģ���Ȼ$N�������������
��������͸���һ�λ��ᣬ������ö����ȥ�Ҷ��ܹܰɡ�\n",me);
	ob=new(__DIR__"obj/lingpai2");
	ob->move(me);
	return 1;
}


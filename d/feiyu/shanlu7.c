// Room: /wiz/louth/a/shanlu7.c

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ���Ѿ��ưܵ�С���̻��Ѷϣ����˴�����������
���˺��Ļҳ���ǽ�ǡ������϶�����֩�����������Ǹ߸ߵ���
��Ҳ�����ʧ�ޣ�������䲻����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shanlu6",
]));
        set("item_desc",([
        "����" : "һ���ɵĲ����پɵ������ˡ����󻹱���Ų������\n",
        "shen xiang" : "һ���ɵĲ����پɵ������ˡ����󻹱���Ų������\n",
]));

	setup();
}

void init()
{
        add_action("do_move","move");
}

int do_move(string arg)
{
        object me = this_player();

        if (arg != "����" && arg != "shen xiang")
                return 0;
        message_vision("$Nʹ�����������񣬷��ֺ��ԭ����һ��ͨ����ɽ��С·\n",me);
        set("exits/north", __DIR__"houlu1");
        call_out("greeting",6);
        return 1;
}

void greeting()
{
        write ("���������Ļص���ԭ����λ�á�\n");
        delete("exits/north");
}


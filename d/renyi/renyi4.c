// Room: /d/renyi/renyi4.c

inherit ROOM;

inherit __DIR__"die";

void create()
{
	set("short", "ׯ��");
	set("long", @LONG
������һ����ë������Ĵ��ţ������ĵ�û��һ���˰��أ�
�ŵ����Ϸ���һ��ľ�ң���д�š�����ׯ���������֡�
LONG
	);

	set(SAFE_ENV, 1);
	set("no_memory", 1);

	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"renyi3",
  "southwest" : __DIR__"renyi5",
]));

	set("outdoors", "renyi");

	setup();
}

int valid_leave(object ob, string dir)
{
	mapping q;

	if(!userp(ob))
		return 1;

	if(mapp(q = ob->query("enyi_class")) && sizeof(q))
		return 1;

	if(dir == "north")
	{
		ob->set_mask_name("İ����");
		ob->set_mask_id("xiake");
	}
	else
	{
		ob->remove_mask_name();
		ob->remove_mask_id();
	}

	return 1;
}

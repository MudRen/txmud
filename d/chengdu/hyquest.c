// Room: /d/chengdu/hyquest.c

inherit ROOM;

protected void come_on_thief(object who)
{
	object ob;
	int exp, unarmed, kee;

	if(!who)
		return;

	ob = new(__DIR__"npc/thief");

	unarmed = who->query_skill("unamred",1);
	exp = who->query("combat_exp");
	kee = who->query("max_kee")/2*3;
	if(unarmed < 50)
		unarmed = 50;
	ob->set("combat_exp", exp>1000000?1000000:exp);
	ob->set_skill("unarmed", unarmed);
	ob->set_skill("dodge", unarmed);
	ob->set_skill("parry", unarmed);
	ob->set("max_kee", kee);
	ob->set("kee", kee);
	ob->set("eff_kee", kee);

	ob->move(this_object());
}

protected void create(object who)
{
	set("short", "��Ժ");
	set("long", @LONG
����һ���ž���СԺ�ӣ��Ĵ���ɨ�øɸɾ������м�һ��ĥ
�̣���ǽ�����°��ż���ʯ�ס�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"minjv",
]));

	set("outdoors", "chengdu");

	set("cannot_build_home", 1);

	setup();
	come_on_thief(who);
}

protected void dest_me()
{
	if(!sizeof(filter_array(all_inventory(this_object()), (: userp :) )))
	{
		destruct(this_object());
		return;
	}

	else
		call_out("dest_me", 3);
}

int valid_leave(object who, string dir)
{
	call_out("dest_me", 3);

	return ::valid_leave(who, dir);
}

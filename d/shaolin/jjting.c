// Room: /d/shaolin/jjting.c

inherit ROOM;

int check_weapon(object who);

void create()
{
	set("short", "�⽣ͤ");
	set("long", @LONG
����ɽ������һ��ͤ�ӣ�Ҳ����������ľ�Զͤ���ϵ�����
���߲��Ŀ��������ˣ�ͤ����һ���ң����顰�⽣ͤ�������Ծ�
�����Ĵ��֣�ͤ����һ��Сʯ�����������¡�һ�����ѵ�С·ͨ
��ɽ�£����Ͽ���һ����ֱ��ɽ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"shandao5",
  "southeast" : __DIR__"xiaolu1",
]));

	set("objects",([
	__DIR__"npc/jjseng" : 1,
]));

	setup();
}

int valid_leave(object ob,string dir)
{
	if(!ob || !stringp(dir))
		return 1;

	if( userp(ob) && !wizardp(ob)
	&& (dir == "northup" || dir == "nu")
	&& ob->query("class") != "shaolin"
	&& !check_weapon(ob) )
		return notify_fail("֪��ɮ˵�������������˷����徲֮�أ�ʩ���뽫��������������\n��");
	else
		return ::valid_leave(ob,dir);
}

int check_weapon(object who)
{
	object checker, *ob;

	checker = present("zhike seng",this_object());
	if(!objectp(checker))
		return 1;

	ob = filter_array(deep_inventory(who),(: $1->is_weapon() :));
	if(arrayp(ob) && sizeof(ob))
		return 0;
	else
		return 1;
}
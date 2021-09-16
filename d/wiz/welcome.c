// Room: /d/wiz/welcome.c

#define BLOCK_CMDS	({"chat","rumor","menpai","tx","save"})
inherit ROOM;

void create()
{
	set("short", "����СԺ");
	set("long", @LONG
������һ���ľ���СԺ�䣬Ժ���滨��ʯ����Ŀ��ȥ����������
�ƣ���ʱ����������������У��˱Ƕ�����������Ļ��㣬�·�����
��ʹ�����ǵ������ɾ���ǰ��������ӳ���м���é�ݡ�
LONG
	);

	set(SAFE_ENV,1);
	set("room_lable","welcome");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"welcome5",
]));

	set("objects",([
		__DIR__"npc/tongzi1" : 1,
]));
	setup();
}

void init()
{
	add_action("block_cmds","",1);
}

int block_cmds(string arg)
{
	if(!wizardp(this_player()) && member_array(query_verb(),BLOCK_CMDS) != -1)
		return 1;
	else
		return 0;
}

int valid_leave(object me,string arg)
{
	if(!present("book",me) && !wizardp(me))
		return notify_fail("С��ͯ����˵�������һ�¡�\n");
	else
		return 1;
}
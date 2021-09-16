// Room: /d/shaolin/lroad3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������µĹ�������Ϊ����ؽ�ի�ã�����һ��ի��ʱ
�䣬���������ĺò����֡������µ�ɮ�˲��ȱ���£�����������
���ԣ�һ��Ҳ������ʲô���ҹ䡣����������������Ժ��������
���㳡����������������ʯ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"yongdao1",
  "south" : __DIR__"w_square",
  "west" : __DIR__"w_court",
]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");

	setup();
}

int valid_leave(object ob,string dir)
{
	if(!ob || !stringp(dir))
		return 1;

	if( (dir == "west" || dir == "w")
	&& ob->query("class") != "shaolin"
	&& !wizardp(ob) )
		return notify_fail("�������µ��Ӳ������ڣ���\n");

	else
		return ::valid_leave(ob,dir);
}
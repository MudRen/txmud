// Room: /d/zuojiacun/lu1.c

inherit ROOM;

void create()
{
	set("short", "��Ҵ��");
	set("long", @LONG
���������Ҵ��ˣ����⿿���������С�������������
�����Բ���Ϊ����һ������£���������������ʱ��Ů����
���ڼ���æһЩ���񣬻�ҪΪ����׼�����ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/path1/zjz9",
  "east" : __DIR__"lu2",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}

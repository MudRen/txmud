
inherit ROOM;

void create()
{
   set("short", "�����Ĳݳ�");
	set("long", @LONG
�����Ǹ����֣������Ǹ�С�ݣ��������
������С·����ȥ���԰�ʦѧ�ա�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
"up" : "/wiz/gaoqi/workroom",
"west" : "/wiz/gaoqi/gaibang/shulin1",
"east" : "/wiz/gaoqi/gaibang/xiaowu",
"south" : "/wiz/gaoqi/gaibang/xiaolu1",
]));	setup();
}

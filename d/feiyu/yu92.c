// Room: /wiz/louth/a/yu92.c

inherit ROOM;

void create()
{
	set("short", "�����Ժ");
	set("long", @LONG
�����������Ժ���ߵ��������ζ����Ũ���ˡ���
��ϸһ�����������������Ļ��ݣ�һȺȺ�۷䡢�����ڻ�
���з��衣������������Ϣ�ң����Ժ����������������֡�
�ϱ�������ĺ��š�
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yuantianer" : 1,
]));
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yu93",
  "north" : __DIR__"yu37",
]));

	set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}

// Room: /wiz/louth/a/houlu2.c

inherit ROOM;

void create()
{
	set("short", "��ɽС·");
	set("long", @LONG
���Ǻ�ɽ��һ��С·��·�����Զ����Ÿ�������Ļ��ݣ�
ʹ�˸о������ޱȡ�����������С·�ϣ���һ���Ŀ�������
�о���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"houlu3",
  "south" : __DIR__"houlu1",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}

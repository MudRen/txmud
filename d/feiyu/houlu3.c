// Room: /wiz/louth/a/houlu3.c

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
  "northwest" : __DIR__"houlu4",
  "south" : __DIR__"houlu2",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}

// Room: /wiz/louth/a/houlu4.c

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
  "southeast" : __DIR__"houlu3",
  "northeast" : __DIR__"houlu5",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}

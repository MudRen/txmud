// Room: /wiz/louth/c/biaojv.c

inherit ROOM;

void create()
{
	set("short", "�����ھ�");
	set("long", @LONG
��������������ĵ������ھ֣��ſڸߴ�����������һ��
���죬�����ý������š����䡱�������֡���ʦ�����ڽ�������
�ƺ���׼�����������ſڵ������������ص�Ѳ�ߡ����������߾�
������·��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wmlu4",
]));
        set("objects",([
        __DIR__"npc/fenggai" : 1,
]));

	setup();
	replace_program(ROOM);
}

// Room: /u/w/wangs/b/kai7.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����һ��ר�����˵���ĳ�����ˮ���壬����Կ���ˮ��
������ϸɴ����ɫ��ˮ�ݵ�ˮ��������������衣����Ҳ��һ��
���ɣ���������ұ�˵����飬�����˵���������Ӧ�ٶȣ����Գ�
�����������ѽ����㷢չ��һ��ר�ŵ�ѧ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai4",
]));

        set("objects",([
        __DIR__"npc/nian" : 1,
        __DIR__"npc/laozhe" : 1,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}

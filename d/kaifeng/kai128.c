// Room: /u/w/wangs/b/kai128.c

inherit ROOM;

void create()
{
	set("short", "ˮ����");
	set("long", @LONG
���ˮ�����������̫������ˮ��ȴ��Ӧ�о��С�������
��ķ���һЩ�������װ���˸�ɫˮ���������ˮ��Ϊ�˱���
���ʣ�ÿ�춼�ɸ��ع�԰��ʱ�����������ܹ˿ͻ�ӭ����ʱ����
���˹��ˮ���꣬����һЩˮ����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai127",
]));

        set("objects",([
        __DIR__"npc/sgboss" : 1,
]));

	setup();
	replace_program(ROOM);
}

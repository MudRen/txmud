// backyard ��Ժ

inherit ROOM;
void create()
{
        set("short", "��Ժ");
        set("long", @LONG
������������ĺ�Ժ�����»��ߣ�Ұ�ݴ�������ǽҲ�Ѿ���
�𲻿���������һЩ��ؤ��ǽ�����ڴ˱�ͷ��˯���ϱ���������
LONG
        );
	set("exits", ([
                "south"           : __DIR__"badroom",
	]) );
        set("objects",([
                "/d/gaibang/npc/yu":1,
	]));

	set("outdoors","changan");
	setup();
	replace_program(ROOM);
}

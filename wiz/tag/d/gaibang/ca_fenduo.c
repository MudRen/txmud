// ca_fenduo.c

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
                "south" : "/d/changan/badroom",
        ]) );
        set("objects",([
                __DIR__"npc/ca_duozhu" : 1,
        ]));

        set("outdoors","changan");
        setup();
        replace_program(ROOM);
}


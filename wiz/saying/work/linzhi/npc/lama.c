//lama.c �������
inherit NPC;
void create()
{
        set_name("����", ({ "lama" }) );
        set("age", 33);
        set("long", "��ľ�µ����\n");
        
        set("str",25);
        set("per",10);
        set("inquiry",([
        "��ľ��":"Сɮ���ǵ�ľ�µ����",
]));        
        setup();
        carry_object(__DIR__"obj/cassock")->wear();
}

//servant.c ͷ�˸������ˡ�
inherit NPC;
void create()
{
        set_name("����", ({ "servant" }) );
        set("age", 28);
        set("long", "һλ���������ˡ�\n");
        
        set("str",25);
        set("per",5);
//        set("inquery",(
//      "��ľ��":"Сɮ���ǵ�ľ�µ����",
//]));
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

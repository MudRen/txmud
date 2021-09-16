// /d/jinghai/npc/ye3.c 

inherit NPC;
void create()
{
      set_name("猎豹",({"lie bao","bao"}));
      set ("long","一只长着黄色皮毛，面露凶光的野豹子。\n");

      set ("race","野兽");
      set ("age",8);
      set ("cor",30);
      set ("con",30);
      set ("str",50);
      set ("max_sen",550);
      set ("max_kee",600);
      set ("max_gin",550);

      set("chat_chance", 10);
      set ("chat_msg",({
      "猎豹的眼睛直直的盯着你。\n",
      "猎豹发出一声令人毛骨耸然的嗥叫。\n",
      (: random_move :),
}));

      set_skill("unarmed",1);
      set_skill("dodge",1);
      set("limbs", ({ "头部", "身体", "爪子", "尾巴" }) );
      set ("verbs",({"bite"}));
      set ("combat_exp",500000+random(100000));

      set("attitude", "killer");
      set_temp("apply/attack",80);
      set_temp("apply/defense",70);

      setup();
}


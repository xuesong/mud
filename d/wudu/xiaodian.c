inherit ROOM;

void create()
{
        set("short", "·��С��");
        set("long", @LONG
������һ��ɽҰС�꣬������ӦһЩʳ���ʱ��ɽ������������
ϡ�٣����һ��Ҳû������·������ϰ���ѵ꿪�����������Ҫ
���ˡ����ڽ���һ��ͷ����������˿��Խ�ȥ��Ϣ��
LONG);

        set("exits", ([
                "east" : __DIR__"shanlu1",
                "west" : __DIR__"neijin",
        ]));

        set("objects", ([
                __DIR__"npc/sun": 1,
        ]));

        setup();
        //replace_program(ROOM);
}

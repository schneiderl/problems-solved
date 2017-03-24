   const triangles = ["541","588","421",
   "40","813","103",
   "436","766","254"];

module.exports.getNumberOfTriangles = function(){
  var n = (triangles.length/3)
  return n;
}
module.exports.getNextTriangle = function(posx, posy){
  return{

    side1: triangles[posx+posy],
    side2: triangles[posx+posy+3],
    side3: triangles[posx+posy+6]
  }
}

